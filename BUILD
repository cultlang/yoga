load("//build_tools:macros.bzl", "header_generator", "dll_generator", "entrypoint_generator")

header_generator(  
  deps = [
    "//util", 
    "//types:headers", 
    "//lisp:headers", 
    "@yoga//:yoga"
  ]
)

dll_generator(
  packages = [
    "types",
    "lisp",
  ],
  deps = [
    "@yoga//:yoga"
  ],
)


