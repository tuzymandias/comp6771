cc_binary(
    name = "template_instantiation",
    srcs = ["template_instantiation.cpp"],
    deps = [],
)

cc_library(
    name = "stack_lib",
    hdrs = ["stack.h"],
    deps = [],
)

cc_binary(
    name = "stack",
    srcs = ["stack_main.cpp"],
    deps = [
        ":stack_lib",
    ],
)

cc_library(
    name = "string_queue_lib",
    hdrs = ["string_queue.h"],
)

cc_binary(
    name = "string_queue",
    srcs = ["string_queue_user.cpp"],
    deps = [
        ":string_queue_lib",
    ],
)

cc_library(
    name = "generic_queue_lib",
    hdrs = ["generic_queue.h"],
)

cc_binary(
    name = "generic_queue",
    srcs = ["generic_queue_user.cpp"],
    deps = [
        ":generic_queue_lib",
    ],
)
