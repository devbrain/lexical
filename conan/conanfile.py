from conans import ConanFile, CMake, tools
import os


class BswConan(ConanFile):
    name = "lexical"
    version = "0.0.1"
    license = "<Put the package license here>"
    author = "Igor Gutnik"
    description = "Basic SoftWare"
    settings = "os" 
    generators = "cmake_find_package"
    
    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(source_folder='lexical', build_folder='build')
        return cmake

    def source(self):
        self.run("git clone git@github.com:devbrain/lexical.git")
    
    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()


