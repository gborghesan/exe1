
#
# Components, types and plugins.
#
# The CMake 'target' names are identical to the first argument of the
# macros below, except for orocos_typegen_headers, where the target is fully
# controlled by generated code of 'typegen'.
#

# Creates a component library libexe1-<target>.so
# and installs in the directory lib/orocos/exe1/
#
orocos_component(source source-component.hpp source-component.cpp) # ...you may add multiple source files
orocos_component(source2 source2-component.hpp source2-component.cpp) # ...you may add multiple source files
orocos_component(sink sink-component.hpp sink-component.cpp) # ...you may add multiple source files
#
# You may add multiple orocos_component statements.

#
# Additional headers:
#
# Installs in the include/orocos/exe1/ directory
#
#orocos_install_headers(source-component.hpp sink-component.hpp) # ...you may add multiple header files
#
# You may add multiple orocos_install_headers statements.

