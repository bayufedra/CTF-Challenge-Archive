package main

import "core:fmt"
import "core:compress/shoco"
import "core:os"
import "core:strings"

main :: proc() {
    args := os.args

    if len(args) < 2 {
        fmt.println("Usage: netcompressor <filename>")
        return
    }

    data, ok := os.read_entire_file(args[1])

    buffer, length := shoco.compress_string(string(data))
    splitted := strings.split(args[1], ".")
    splitted[len(splitted) - 1] = "netcomp"
    filename := strings.join(splitted, ".")
    os.write_entire_file(filename, buffer)
}