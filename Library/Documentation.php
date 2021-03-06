<?php

/*
 +--------------------------------------------------------------------------+
 | Zephir Language                                                          |
 +--------------------------------------------------------------------------+
 | Copyright (c) 2013-2014 Zephir Team and contributors                     |
 +--------------------------------------------------------------------------+
 | This source file is subject the MIT license, that is bundled with        |
 | this package in the file LICENSE, and is available through the           |
 | world-wide-web at the following url:                                     |
 | http://zephir-lang.com/license.html                                      |
 |                                                                          |
 | If you did not receive a copy of the MIT license and are unable          |
 | to obtain it through the world-wide-web, please send a note to           |
 | license@zephir-lang.com so we can mail you a copy immediately.           |
 +--------------------------------------------------------------------------+
*/

namespace Zephir;

use Zephir\Documentation\File;
use Zephir\Documentation\Theme;
use Zephir\Documentation\NamespaceAccessor;
use Zephir\Logger;

/**
 * Documentation Generator
 */
class Documentation
{

    /**
     * @var Config
     */
    protected $config;

    /**
     * @var CompilerFile[]
     */
    protected $classes;

    /**
     * @var Theme
     */
    protected $theme;

    protected $logger;

    /**
     * @param CompilerFile[] $classes
     * @param Config $config
     * @param Logger $logger
     * @throws ConfigException
     * @throws Exception
     */
    public function __construct(array $classes, Config $config, Logger $logger)
    {
        ksort($classes);

        $this->config = $config;
        $this->classes = $classes;
        $this->logger  = $logger;

        $themeConfig = $config->get("theme", "api");
        $themeConfig["options"]["version"] = $config->get('version');

        if (!$themeConfig) {
            throw new ConfigException("Theme configuration is not present");
        }

        if (!isset($themeConfig["name"]) || !$themeConfig["name"]) {
            throw new ConfigException("There is no theme ");
        }

        $themeDir = realpath(ZEPHIRPATH . "/templates/Api/themes/" . $themeConfig["name"]);

        if (!file_exists($themeDir)) {
            throw new ConfigException("There is no theme name " . $themeConfig["name"]);
        }

        $outputDir = $this->config->get('path', 'api');
        $outputDir = str_replace('%version%', $this->config->get('version'), $outputDir);

        if (!$outputDir) {
            throw new ConfigException("Api path is not configured");
        }

        if (!file_exists($outputDir)) {
            if (!mkdir($outputDir, 0777, true)) {
                throw new Exception("Can't write output directory $outputDir");
            }
        }

        if (!is_writable($outputDir)) {
            throw new Exception("Can't write output directory $outputDir");
        }

        $this->theme = new Theme($themeDir, $outputDir, $themeConfig);
    }

    public function build()
    {
        $byNamespace = array();

        foreach ($this->classes as $className => $class) {
            // class files (class/ns1/n2/class.html)
            $cfile = new File\ClassFile($this->config, $class);
            $this->theme->drawFile($cfile);

            // class source file (source/ns1/n2/class.html)
            $sfile = new File\SourceFile($this->config, $class);
            $this->theme->drawFile($sfile);
        }

        // classes file (classes.html)
        $file = new File\ClassesFile($this->config, $this->classes);
        $this->theme->drawFile($file);


        $namespaceAccessor = new NamespaceAccessor($this->classes);
        $namespaceAccessor->build();

        $byNamespace = $namespaceAccessor->getByNamespace();

        foreach ($byNamespace as $namespaceName => $nh) {
            // namespace files (namespace/ns1/n2/namespace.html)
            $nfile = new File\NamespaceFile($this->config, $nh);
            $this->theme->drawFile($nfile);
        }

        // namespaces files (namespaces.html)
        $nsfile = new File\NamespacesFile($this->config, $namespaceAccessor);
        $this->theme->drawFile($nsfile);


        // index (index.html)
        $indexfile = new File\IndexFile($this->config, $namespaceAccessor);
        $this->theme->drawFile($indexfile);

        $this->theme->buildStaticDirectory();

        $JsonClassDef = $this->theme->buildJsonClassDefinition($this->classes, $namespaceAccessor);
        $this->theme->createFile("asset/api_definition.js", "var ZephirApi = $JsonClassDef;");
    }

    public static function classUrl($c)
    {
        if ($c instanceof ClassDefinition) {
            $cname = $c->getCompleteName();
        } else {
            $cname = $c;
        }

        return "/class/" . str_replace("\\", "/", $cname) . ".html";
    }

    public static function namespaceUrl($ns)
    {
        return "/namespace/" . str_replace("\\", "/", $ns) . ".html";
    }

    public static function sourceUrl(ClassDefinition $c)
    {
        return "/source/" . str_replace("\\", "/", $c->getCompleteName()) . ".html";
    }
}
