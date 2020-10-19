load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "bit",
    srcs = ["bit.c"],
    hdrs = ["bit.h"],
)

cc_library(
    name = "bitree",
    srcs = ["bitree.c"],
    hdrs = ["bitree.h"],
)

cc_test(
    name = "bit_test",
    srcs = ["bit_test.c"],
    deps = [
        "@gtest",
    ],
)

cc_library(
    name = "compress",
    srcs = ["huffman.c"],
    hdrs = ["compress.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    copts = [],
    deps = [
        "bit",
        "bitree",
        "compress",
    ],
)
