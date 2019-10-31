from conans import ConanFile, CMake, tools


class FixedPointConan(ConanFile):
    name = "fixed-point"
    version = "0.1.1"
    license = "MIT"
    author = "Matthew Knight <mgk1795@gmail.com>"
    url = "https://github.com/matt1795/fixed-point"
    description = "header-only library for fixed point arithmetic"
    topics = ("fixed-point", "embedded", "math")
    generators = "cmake"
    requires = "gcem/1.12.0@matt1795/stable"
    exports_sources = "include/*"
    no_copy_source = True

    def package(self):
        self.copy("*.hpp")

    def package_id(self):
        self.info.header_only()
