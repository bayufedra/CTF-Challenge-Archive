(module
 (type $i32_=>_none (func (param i32)))
 (type $none_=>_none (func))
 (type $i32_i32_=>_i32 (func (param i32 i32) (result i32)))
 (type $i32_=>_i32 (func (param i32) (result i32)))
 (type $i32_i32_=>_none (func (param i32 i32)))
 (type $i32_i32_i32_i32_=>_none (func (param i32 i32 i32 i32)))
 (type $i32_i32_i64_=>_none (func (param i32 i32 i64)))
 (type $none_=>_i32 (func (result i32)))
 (type $i32_=>_f64 (func (param i32) (result f64)))
 (import "env" "abort" (func $~lib/builtins/abort (param i32 i32 i32 i32)))
 (global $~lib/rt/itcms/total (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/threshold (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/state (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/visitCount (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/pinSpace (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/iter (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/toSpace (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/white (mut i32) (i32.const 0))
 (global $~lib/rt/itcms/fromSpace (mut i32) (i32.const 0))
 (global $~lib/rt/tlsf/ROOT (mut i32) (i32.const 0))
 (global $~lib/rt/__rtti_base i32 (i32.const 7312))
 (global $~lib/memory/__stack_pointer (mut i32) (i32.const 40100))
 (memory $0 1)
 (data $0 (i32.const 1036) "<")
 (data $0.1 (i32.const 1048) "\02\00\00\00(\00\00\00A\00l\00l\00o\00c\00a\00t\00i\00o\00n\00 \00t\00o\00o\00 \00l\00a\00r\00g\00e")
 (data $1 (i32.const 1100) "<")
 (data $1.1 (i32.const 1112) "\02\00\00\00 \00\00\00~\00l\00i\00b\00/\00r\00t\00/\00i\00t\00c\00m\00s\00.\00t\00s")
 (data $4 (i32.const 1228) "<")
 (data $4.1 (i32.const 1240) "\02\00\00\00$\00\00\00I\00n\00d\00e\00x\00 \00o\00u\00t\00 \00o\00f\00 \00r\00a\00n\00g\00e")
 (data $5 (i32.const 1292) ",")
 (data $5.1 (i32.const 1304) "\02\00\00\00\14\00\00\00~\00l\00i\00b\00/\00r\00t\00.\00t\00s")
 (data $7 (i32.const 1372) "<")
 (data $7.1 (i32.const 1384) "\02\00\00\00\1e\00\00\00~\00l\00i\00b\00/\00r\00t\00/\00t\00l\00s\00f\00.\00t\00s")
 (data $8 (i32.const 1436) ",")
 (data $8.1 (i32.const 1448) "\02\00\00\00\1a\00\00\00U\00R\00I\00 \00m\00a\00l\00f\00o\00r\00m\00e\00d")
 (data $9 (i32.const 1484) "<")
 (data $9.1 (i32.const 1496) "\02\00\00\00 \00\00\00~\00l\00i\00b\00/\00u\00t\00i\00l\00/\00u\00r\00i\00.\00t\00s")
 (data $10 (i32.const 1548) "\01\01\00\01\00\00\00\00\01\01\00\00\01")
 (data $10.1 (i32.const 1571) "\01\01\00\01\00\01\01")
 (data $11 (i32.const 1580) "\9c\05")
 (data $11.1 (i32.const 1592) "\02\00\00\00~\05\00\00\n\00 \00 \00<\00n\00a\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00 \00i\00s\00-\00p\00r\00i\00m\00a\00r\00y\00\"\00 \00r\00o\00l\00e\00=\00\"\00n\00a\00v\00i\00g\00a\00t\00i\00o\00n\00\"\00 \00a\00r\00i\00a\00-\00l\00a\00b\00e\00l\00=\00\"\00m\00a\00i\00n\00 \00n\00a\00v\00i\00g\00a\00t\00i\00o\00n\00\"\00>\00\n\00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00b\00r\00a\00n\00d\00\"\00>\00\n\00 \00 \00 \00 \00<\00a\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00i\00t\00e\00m\00\"\00 \00h\00r\00e\00f\00=\00\"\00#\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00i\00m\00g\00 \00s\00r\00c\00=\00\"\00l\00o\00g\00o\00.\00p\00n\00g\00\"\00 \00a\00l\00t\00=\00\"\00L\00o\00g\00o\00\"\00>\00\n\00 \00 \00 \00 \00<\00/\00a\00>\00\n\00 \00 \00 \00 \00<\00b\00u\00t\00t\00o\00n\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00b\00u\00r\00g\00e\00r\00 \00b\00u\00r\00g\00e\00r\00\"\00 \00a\00r\00i\00a\00-\00l\00a\00b\00e\00l\00=\00\"\00m\00e\00n\00u\00\"\00 \00a\00r\00i\00a\00-\00e\00x\00p\00a\00n\00d\00e\00d\00=\00\"\00f\00a\00l\00s\00e\00\"\00 \00d\00a\00t\00a\00-\00t\00a\00r\00g\00e\00t\00=\00\"\00n\00a\00v\00b\00a\00r\00M\00e\00n\00u\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00s\00p\00a\00n\00 \00a\00r\00i\00a\00-\00h\00i\00d\00d\00e\00n\00=\00\"\00t\00r\00u\00e\00\"\00>\00<\00/\00s\00p\00a\00n\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00s\00p\00a\00n\00 \00a\00r\00i\00a\00-\00h\00i\00d\00d\00e\00n\00=\00\"\00t\00r\00u\00e\00\"\00>\00<\00/\00s\00p\00a\00n\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00s\00p\00a\00n\00 \00a\00r\00i\00a\00-\00h\00i\00d\00d\00e\00n\00=\00\"\00t\00r\00u\00e\00\"\00>\00<\00/\00s\00p\00a\00n\00>\00\n\00 \00 \00 \00 \00<\00/\00b\00u\00t\00t\00o\00n\00>\00\n\00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00m\00e\00n\00u\00\"\00 \00i\00d\00=\00\"\00n\00a\00v\00b\00a\00r\00M\00e\00n\00u\00\"\00>\00\n\00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00s\00t\00a\00r\00t\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00a\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00i\00t\00e\00m\00\"\00 \00h\00r\00e\00f\00=\00\"\00#\00\"\00>\00H\00o\00m\00e\00<\00/\00a\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00a\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00i\00t\00e\00m\00\"\00 \00h\00r\00e\00f\00=\00\"\00#\00a\00b\00o\00u\00t\00\"\00>\00A\00b\00o\00u\00t\00<\00/\00a\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00a\00 \00c\00l\00a\00s\00s\00=\00\"\00n\00a\00v\00b\00a\00r\00-\00i\00t\00e\00m\00\"\00 \00h\00r\00e\00f\00=\00\"\00#\00c\00o\00n\00t\00a\00c\00t\00\"\00>\00C\00o\00n\00t\00a\00c\00t\00<\00/\00a\00>\00\n\00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00<\00/\00d\00i\00v\00>\00\n\00<\00/\00n\00a\00v\00>\00\n\00 \00 ")
 (data $12 (i32.const 3020) "\1c")
 (data $12.1 (i32.const 3032) "\02")
 (data $13 (i32.const 3052) "\bc\01")
 (data $13.1 (i32.const 3064) "\02\00\00\00\a0\01\00\00\n\00<\00s\00e\00c\00t\00i\00o\00n\00 \00c\00l\00a\00s\00s\00=\00\"\00h\00e\00r\00o\00 \00i\00s\00-\00f\00u\00l\00l\00h\00e\00i\00g\00h\00t\00\"\00>\00\n\00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00h\00e\00r\00o\00-\00b\00o\00d\00y\00\"\00>\00\n\00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00a\00i\00n\00e\00r\00 \00h\00a\00s\00-\00t\00e\00x\00t\00-\00c\00e\00n\00t\00e\00r\00e\00d\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00h\001\00 \00c\00l\00a\00s\00s\00=\00\"\00t\00i\00t\00l\00e\00 \00i\00s\00-\00s\00i\00z\00e\00-\001\00\"\00>\00W\00e\00l\00c\00o\00m\00e\00 \00t\00o\00 \00t\00h\00e\00 \00H\00o\00m\00e\00 \00P\00a\00g\00e\00!\00<\00/\00h\001\00>\00\n\00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00<\00/\00d\00i\00v\00>\00\n\00<\00/\00s\00e\00c\00t\00i\00o\00n\00>\00\n\00 \00 ")
 (data $14 (i32.const 3500) "\1c")
 (data $14.1 (i32.const 3512) "\02\00\00\00\n\00\00\00a\00b\00o\00u\00t")
 (data $15 (i32.const 3532) "\bc\04")
 (data $15.1 (i32.const 3544) "\02\00\00\00\a2\04\00\00\n\00<\00s\00e\00c\00t\00i\00o\00n\00 \00i\00d\00=\00\"\00a\00b\00o\00u\00t\00\"\00 \00c\00l\00a\00s\00s\00=\00\"\00s\00e\00c\00t\00i\00o\00n\00\"\00>\00\n\00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00a\00i\00n\00e\00r\00\"\00>\00\n\00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00s\00 \00i\00s\00-\00v\00c\00e\00n\00t\00e\00r\00e\00d\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00h\002\00 \00c\00l\00a\00s\00s\00=\00\"\00t\00i\00t\00l\00e\00\"\00>\00A\00b\00o\00u\00t\00 \00U\00s\00<\00/\00h\002\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00p\00>\00L\00o\00r\00e\00m\00 \00i\00p\00s\00u\00m\00 \00d\00o\00l\00o\00r\00 \00s\00i\00t\00 \00a\00m\00e\00t\00,\00 \00c\00o\00n\00s\00e\00c\00t\00e\00t\00u\00r\00 \00a\00d\00i\00p\00i\00s\00c\00i\00n\00g\00 \00e\00l\00i\00t\00.\00 \00N\00u\00l\00l\00a\00m\00 \00e\00u\00i\00s\00m\00o\00d\00 \00e\00x\00 \00i\00d\00 \00e\00r\00a\00t\00 \00s\00a\00g\00i\00t\00t\00i\00s\00 \00e\00l\00e\00i\00f\00e\00n\00d\00.\00 \00A\00e\00n\00e\00a\00n\00 \00p\00u\00l\00v\00i\00n\00a\00r\00,\00 \00s\00e\00m\00 \00i\00d\00 \00a\00l\00i\00q\00u\00a\00m\00 \00a\00c\00c\00u\00m\00s\00a\00n\00,\00 \00j\00u\00s\00t\00o\00 \00n\00u\00n\00c\00 \00s\00e\00m\00p\00e\00r\00 \00m\00a\00s\00s\00a\00,\00 \00n\00o\00n\00 \00p\00e\00l\00l\00e\00n\00t\00e\00s\00q\00u\00e\00 \00u\00r\00n\00a\00 \00j\00u\00s\00t\00o\00 \00s\00i\00t\00 \00a\00m\00e\00t\00 \00l\00e\00c\00t\00u\00s\00.\00<\00/\00p\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00f\00i\00g\00u\00r\00e\00 \00c\00l\00a\00s\00s\00=\00\"\00i\00m\00a\00g\00e\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00i\00m\00g\00 \00s\00r\00c\00=\00\"\00a\00b\00o\00u\00t\00-\00i\00m\00a\00g\00e\00.\00j\00p\00g\00\"\00 \00a\00l\00t\00=\00\"\00A\00b\00o\00u\00t\00 \00U\00s\00 \00I\00m\00a\00g\00e\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00f\00i\00g\00u\00r\00e\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00<\00/\00d\00i\00v\00>\00\n\00<\00/\00s\00e\00c\00t\00i\00o\00n\00>\00\n\00 \00 ")
 (data $16 (i32.const 4748) ",")
 (data $16.1 (i32.const 4760) "\02\00\00\00\0e\00\00\00c\00o\00n\00t\00a\00c\00t")
 (data $17 (i32.const 4796) "\dc\08")
 (data $17.1 (i32.const 4808) "\02\00\00\00\c0\08\00\00\n\00<\00s\00e\00c\00t\00i\00o\00n\00 \00i\00d\00=\00\"\00c\00o\00n\00t\00a\00c\00t\00\"\00 \00c\00l\00a\00s\00s\00=\00\"\00s\00e\00c\00t\00i\00o\00n\00\"\00>\00\n\00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00a\00i\00n\00e\00r\00\"\00>\00\n\00 \00 \00 \00 \00<\00h\002\00 \00c\00l\00a\00s\00s\00=\00\"\00t\00i\00t\00l\00e\00\"\00>\00C\00o\00n\00t\00a\00c\00t\00 \00U\00s\00<\00/\00h\002\00>\00\n\00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00s\00 \00i\00s\00-\00m\00u\00l\00t\00i\00l\00i\00n\00e\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00 \00i\00s\00-\00h\00a\00l\00f\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00f\00i\00e\00l\00d\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00l\00a\00b\00e\00l\00 \00c\00l\00a\00s\00s\00=\00\"\00l\00a\00b\00e\00l\00\"\00>\00N\00a\00m\00e\00<\00/\00l\00a\00b\00e\00l\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00r\00o\00l\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00i\00n\00p\00u\00t\00 \00c\00l\00a\00s\00s\00=\00\"\00i\00n\00p\00u\00t\00\"\00 \00t\00y\00p\00e\00=\00\"\00t\00e\00x\00t\00\"\00 \00p\00l\00a\00c\00e\00h\00o\00l\00d\00e\00r\00=\00\"\00Y\00o\00u\00r\00 \00N\00a\00m\00e\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00f\00i\00e\00l\00d\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00l\00a\00b\00e\00l\00 \00c\00l\00a\00s\00s\00=\00\"\00l\00a\00b\00e\00l\00\"\00>\00E\00m\00a\00i\00l\00<\00/\00l\00a\00b\00e\00l\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00r\00o\00l\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00i\00n\00p\00u\00t\00 \00c\00l\00a\00s\00s\00=\00\"\00i\00n\00p\00u\00t\00\"\00 \00t\00y\00p\00e\00=\00\"\00e\00m\00a\00i\00l\00\"\00 \00p\00l\00a\00c\00e\00h\00o\00l\00d\00e\00r\00=\00\"\00Y\00o\00u\00r\00 \00E\00m\00a\00i\00l\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00 \00i\00s\00-\00h\00a\00l\00f\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00f\00i\00e\00l\00d\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00l\00a\00b\00e\00l\00 \00c\00l\00a\00s\00s\00=\00\"\00l\00a\00b\00e\00l\00\"\00>\00M\00e\00s\00s\00a\00g\00e\00<\00/\00l\00a\00b\00e\00l\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00r\00o\00l\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00t\00e\00x\00t\00a\00r\00e\00a\00 \00c\00l\00a\00s\00s\00=\00\"\00t\00e\00x\00t\00a\00r\00e\00a\00\"\00 \00p\00l\00a\00c\00e\00h\00o\00l\00d\00e\00r\00=\00\"\00Y\00o\00u\00r\00 \00M\00e\00s\00s\00a\00g\00e\00\"\00>\00<\00/\00t\00e\00x\00t\00a\00r\00e\00a\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00l\00u\00m\00n\00 \00i\00s\00-\00f\00u\00l\00l\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00f\00i\00e\00l\00d\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00d\00i\00v\00 \00c\00l\00a\00s\00s\00=\00\"\00c\00o\00n\00t\00r\00o\00l\00\"\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00b\00u\00t\00t\00o\00n\00 \00c\00l\00a\00s\00s\00=\00\"\00b\00u\00t\00t\00o\00n\00 \00i\00s\00-\00p\00r\00i\00m\00a\00r\00y\00\"\00 \00t\00y\00p\00e\00=\00\"\00s\00u\00b\00m\00i\00t\00\"\00>\00S\00u\00b\00m\00i\00t\00<\00/\00b\00u\00t\00t\00o\00n\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00 \00 \00<\00/\00d\00i\00v\00>\00\n\00 \00 \00<\00/\00d\00i\00v\00>\00\n\00<\00/\00s\00e\00c\00t\00i\00o\00n\00>\00\n\00 \00 ")
 (data $18 (i32.const 7068) "\1c")
 (data $18.1 (i32.const 7080) "\02\00\00\00\02\00\00\00!")
 (data $19 (i32.const 7100) "L")
 (data $19.1 (i32.const 7112) "\02\00\00\00.\00\00\00<\00h\001\00>\00P\00a\00g\00e\00 \00N\00o\00t\00 \00F\00o\00u\00n\00d\00<\00/\00h\001\00>")
 (data $20 (i32.const 7180) "<")
 (data $20.1 (i32.const 7192) "\02\00\00\00*\00\00\00O\00b\00j\00e\00c\00t\00 \00a\00l\00r\00e\00a\00d\00y\00 \00p\00i\00n\00n\00e\00d")
 (data $21 (i32.const 7244) "<")
 (data $21.1 (i32.const 7256) "\02\00\00\00(\00\00\00O\00b\00j\00e\00c\00t\00 \00i\00s\00 \00n\00o\00t\00 \00p\00i\00n\00n\00e\00d")
 (data $22 (i32.const 7312) "\04\00\00\00 \00\00\00 \00\00\00 ")
 (export "__new" (func $~lib/rt/itcms/__new))
 (export "__pin" (func $~lib/rt/itcms/__pin))
 (export "__unpin" (func $~lib/rt/itcms/__unpin))
 (export "__collect" (func $~lib/rt/itcms/__collect))
 (export "__rtti_base" (global $~lib/rt/__rtti_base))
 (export "memory" (memory $0))
 (export "index" (func $export:assembly/index/index))
 (start $~start)
 (func $~lib/rt/itcms/visitRoots
  (local $0 i32)
  (local $1 i32)
  i32.const 1248
  call $byn-split-outlined-A$~lib/rt/itcms/__visit
  i32.const 1056
  call $byn-split-outlined-A$~lib/rt/itcms/__visit
  i32.const 7200
  call $byn-split-outlined-A$~lib/rt/itcms/__visit
  i32.const 7264
  call $byn-split-outlined-A$~lib/rt/itcms/__visit
  i32.const 1456
  call $byn-split-outlined-A$~lib/rt/itcms/__visit
  global.get $~lib/rt/itcms/pinSpace
  local.tee $1
  i32.load $0 offset=4
  i32.const -4
  i32.and
  local.set $0
  loop $while-continue|0
   local.get $0
   local.get $1
   i32.ne
   if
    local.get $0
    i32.load $0 offset=4
    i32.const 3
    i32.and
    i32.const 3
    i32.ne
    if
     i32.const 0
     i32.const 1120
     i32.const 160
     i32.const 16
     call $~lib/builtins/abort
     unreachable
    end
    local.get $0
    i32.const 20
    i32.add
    call $~lib/rt/__visit_members
    local.get $0
    i32.load $0 offset=4
    i32.const -4
    i32.and
    local.set $0
    br $while-continue|0
   end
  end
 )
 (func $~lib/rt/itcms/Object#unlink (param $0 i32)
  (local $1 i32)
  local.get $0
  i32.load $0 offset=4
  i32.const -4
  i32.and
  local.tee $1
  i32.eqz
  if
   local.get $0
   i32.load $0 offset=8
   i32.eqz
   local.get $0
   i32.const 40100
   i32.lt_u
   i32.and
   i32.eqz
   if
    i32.const 0
    i32.const 1120
    i32.const 128
    i32.const 18
    call $~lib/builtins/abort
    unreachable
   end
   return
  end
  local.get $0
  i32.load $0 offset=8
  local.tee $0
  i32.eqz
  if
   i32.const 0
   i32.const 1120
   i32.const 132
   i32.const 16
   call $~lib/builtins/abort
   unreachable
  end
  local.get $1
  local.get $0
  i32.store $0 offset=8
  local.get $0
  local.get $1
  local.get $0
  i32.load $0 offset=4
  i32.const 3
  i32.and
  i32.or
  i32.store $0 offset=4
 )
 (func $~lib/rt/itcms/Object#makeGray (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  local.get $0
  global.get $~lib/rt/itcms/iter
  i32.eq
  if
   local.get $0
   i32.load $0 offset=8
   local.tee $1
   i32.eqz
   if
    i32.const 0
    i32.const 1120
    i32.const 148
    i32.const 30
    call $~lib/builtins/abort
    unreachable
   end
   local.get $1
   global.set $~lib/rt/itcms/iter
  end
  local.get $0
  call $~lib/rt/itcms/Object#unlink
  global.get $~lib/rt/itcms/toSpace
  local.set $1
  local.get $0
  i32.load $0 offset=12
  local.tee $2
  i32.const 2
  i32.le_u
  if (result i32)
   i32.const 1
  else
   local.get $2
   i32.const 7312
   i32.load $0
   i32.gt_u
   if
    i32.const 1248
    i32.const 1312
    i32.const 21
    i32.const 28
    call $~lib/builtins/abort
    unreachable
   end
   local.get $2
   i32.const 2
   i32.shl
   i32.const 7316
   i32.add
   i32.load $0
   i32.const 32
   i32.and
  end
  local.set $3
  local.get $1
  i32.load $0 offset=8
  local.set $2
  local.get $0
  global.get $~lib/rt/itcms/white
  i32.eqz
  i32.const 2
  local.get $3
  select
  local.get $1
  i32.or
  i32.store $0 offset=4
  local.get $0
  local.get $2
  i32.store $0 offset=8
  local.get $2
  local.get $0
  local.get $2
  i32.load $0 offset=4
  i32.const 3
  i32.and
  i32.or
  i32.store $0 offset=4
  local.get $1
  local.get $0
  i32.store $0 offset=8
 )
 (func $~lib/rt/tlsf/removeBlock (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  local.get $1
  i32.load $0
  local.tee $2
  i32.const 1
  i32.and
  i32.eqz
  if
   i32.const 0
   i32.const 1392
   i32.const 268
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $2
  i32.const -4
  i32.and
  local.tee $2
  i32.const 12
  i32.lt_u
  if
   i32.const 0
   i32.const 1392
   i32.const 270
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $2
  i32.const 256
  i32.lt_u
  if (result i32)
   local.get $2
   i32.const 4
   i32.shr_u
  else
   i32.const 31
   i32.const 1073741820
   local.get $2
   local.get $2
   i32.const 1073741820
   i32.ge_u
   select
   local.tee $2
   i32.clz
   i32.sub
   local.tee $4
   i32.const 7
   i32.sub
   local.set $3
   local.get $2
   local.get $4
   i32.const 4
   i32.sub
   i32.shr_u
   i32.const 16
   i32.xor
  end
  local.tee $2
  i32.const 16
  i32.lt_u
  local.get $3
  i32.const 23
  i32.lt_u
  i32.and
  i32.eqz
  if
   i32.const 0
   i32.const 1392
   i32.const 284
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $1
  i32.load $0 offset=8
  local.set $5
  local.get $1
  i32.load $0 offset=4
  local.tee $4
  if
   local.get $4
   local.get $5
   i32.store $0 offset=8
  end
  local.get $5
  if
   local.get $5
   local.get $4
   i32.store $0 offset=4
  end
  local.get $1
  local.get $0
  local.get $3
  i32.const 4
  i32.shl
  local.get $2
  i32.add
  i32.const 2
  i32.shl
  i32.add
  i32.load $0 offset=96
  i32.eq
  if
   local.get $0
   local.get $3
   i32.const 4
   i32.shl
   local.get $2
   i32.add
   i32.const 2
   i32.shl
   i32.add
   local.get $5
   i32.store $0 offset=96
   local.get $5
   i32.eqz
   if
    local.get $0
    local.get $3
    i32.const 2
    i32.shl
    i32.add
    local.tee $1
    i32.load $0 offset=4
    i32.const -2
    local.get $2
    i32.rotl
    i32.and
    local.set $2
    local.get $1
    local.get $2
    i32.store $0 offset=4
    local.get $2
    i32.eqz
    if
     local.get $0
     local.get $0
     i32.load $0
     i32.const -2
     local.get $3
     i32.rotl
     i32.and
     i32.store $0
    end
   end
  end
 )
 (func $~lib/rt/tlsf/insertBlock (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  local.get $1
  i32.eqz
  if
   i32.const 0
   i32.const 1392
   i32.const 201
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $1
  i32.load $0
  local.tee $3
  i32.const 1
  i32.and
  i32.eqz
  if
   i32.const 0
   i32.const 1392
   i32.const 203
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $1
  i32.const 4
  i32.add
  local.get $1
  i32.load $0
  i32.const -4
  i32.and
  i32.add
  local.tee $4
  i32.load $0
  local.tee $2
  i32.const 1
  i32.and
  if
   local.get $0
   local.get $4
   call $~lib/rt/tlsf/removeBlock
   local.get $1
   local.get $3
   i32.const 4
   i32.add
   local.get $2
   i32.const -4
   i32.and
   i32.add
   local.tee $3
   i32.store $0
   local.get $1
   i32.const 4
   i32.add
   local.get $1
   i32.load $0
   i32.const -4
   i32.and
   i32.add
   local.tee $4
   i32.load $0
   local.set $2
  end
  local.get $3
  i32.const 2
  i32.and
  if
   local.get $1
   i32.const 4
   i32.sub
   i32.load $0
   local.tee $1
   i32.load $0
   local.tee $6
   i32.const 1
   i32.and
   i32.eqz
   if
    i32.const 0
    i32.const 1392
    i32.const 221
    i32.const 16
    call $~lib/builtins/abort
    unreachable
   end
   local.get $0
   local.get $1
   call $~lib/rt/tlsf/removeBlock
   local.get $1
   local.get $6
   i32.const 4
   i32.add
   local.get $3
   i32.const -4
   i32.and
   i32.add
   local.tee $3
   i32.store $0
  end
  local.get $4
  local.get $2
  i32.const 2
  i32.or
  i32.store $0
  local.get $3
  i32.const -4
  i32.and
  local.tee $2
  i32.const 12
  i32.lt_u
  if
   i32.const 0
   i32.const 1392
   i32.const 233
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $4
  local.get $1
  i32.const 4
  i32.add
  local.get $2
  i32.add
  i32.ne
  if
   i32.const 0
   i32.const 1392
   i32.const 234
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $4
  i32.const 4
  i32.sub
  local.get $1
  i32.store $0
  local.get $2
  i32.const 256
  i32.lt_u
  if (result i32)
   local.get $2
   i32.const 4
   i32.shr_u
  else
   i32.const 31
   i32.const 1073741820
   local.get $2
   local.get $2
   i32.const 1073741820
   i32.ge_u
   select
   local.tee $2
   i32.clz
   i32.sub
   local.tee $3
   i32.const 7
   i32.sub
   local.set $5
   local.get $2
   local.get $3
   i32.const 4
   i32.sub
   i32.shr_u
   i32.const 16
   i32.xor
  end
  local.tee $2
  i32.const 16
  i32.lt_u
  local.get $5
  i32.const 23
  i32.lt_u
  i32.and
  i32.eqz
  if
   i32.const 0
   i32.const 1392
   i32.const 251
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $0
  local.get $5
  i32.const 4
  i32.shl
  local.get $2
  i32.add
  i32.const 2
  i32.shl
  i32.add
  i32.load $0 offset=96
  local.set $3
  local.get $1
  i32.const 0
  i32.store $0 offset=4
  local.get $1
  local.get $3
  i32.store $0 offset=8
  local.get $3
  if
   local.get $3
   local.get $1
   i32.store $0 offset=4
  end
  local.get $0
  local.get $5
  i32.const 4
  i32.shl
  local.get $2
  i32.add
  i32.const 2
  i32.shl
  i32.add
  local.get $1
  i32.store $0 offset=96
  local.get $0
  local.get $0
  i32.load $0
  i32.const 1
  local.get $5
  i32.shl
  i32.or
  i32.store $0
  local.get $0
  local.get $5
  i32.const 2
  i32.shl
  i32.add
  local.tee $0
  local.get $0
  i32.load $0 offset=4
  i32.const 1
  local.get $2
  i32.shl
  i32.or
  i32.store $0 offset=4
 )
 (func $~lib/rt/tlsf/addMemory (param $0 i32) (param $1 i32) (param $2 i64)
  (local $3 i32)
  (local $4 i32)
  local.get $2
  local.get $1
  i64.extend_i32_u
  i64.lt_u
  if
   i32.const 0
   i32.const 1392
   i32.const 378
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $1
  i32.const 19
  i32.add
  i32.const -16
  i32.and
  i32.const 4
  i32.sub
  local.set $1
  local.get $0
  i32.load $0 offset=1568
  local.tee $4
  if
   local.get $4
   i32.const 4
   i32.add
   local.get $1
   i32.gt_u
   if
    i32.const 0
    i32.const 1392
    i32.const 385
    i32.const 16
    call $~lib/builtins/abort
    unreachable
   end
   local.get $1
   i32.const 16
   i32.sub
   local.get $4
   i32.eq
   if
    local.get $4
    i32.load $0
    local.set $3
    local.get $1
    i32.const 16
    i32.sub
    local.set $1
   end
  else
   local.get $0
   i32.const 1572
   i32.add
   local.get $1
   i32.gt_u
   if
    i32.const 0
    i32.const 1392
    i32.const 398
    i32.const 5
    call $~lib/builtins/abort
    unreachable
   end
  end
  local.get $2
  i32.wrap_i64
  i32.const -16
  i32.and
  local.get $1
  i32.sub
  local.tee $4
  i32.const 20
  i32.lt_u
  if
   return
  end
  local.get $1
  local.get $3
  i32.const 2
  i32.and
  local.get $4
  i32.const 8
  i32.sub
  local.tee $3
  i32.const 1
  i32.or
  i32.or
  i32.store $0
  local.get $1
  i32.const 0
  i32.store $0 offset=4
  local.get $1
  i32.const 0
  i32.store $0 offset=8
  local.get $1
  i32.const 4
  i32.add
  local.get $3
  i32.add
  local.tee $3
  i32.const 2
  i32.store $0
  local.get $0
  local.get $3
  i32.store $0 offset=1568
  local.get $0
  local.get $1
  call $~lib/rt/tlsf/insertBlock
 )
 (func $~lib/rt/tlsf/initialize
  (local $0 i32)
  (local $1 i32)
  memory.size $0
  local.tee $1
  i32.const 0
  i32.le_s
  if (result i32)
   i32.const 1
   local.get $1
   i32.sub
   memory.grow $0
   i32.const 0
   i32.lt_s
  else
   i32.const 0
  end
  if
   unreachable
  end
  i32.const 40112
  i32.const 0
  i32.store $0
  i32.const 41680
  i32.const 0
  i32.store $0
  loop $for-loop|0
   local.get $0
   i32.const 23
   i32.lt_u
   if
    local.get $0
    i32.const 2
    i32.shl
    i32.const 40112
    i32.add
    i32.const 0
    i32.store $0 offset=4
    i32.const 0
    local.set $1
    loop $for-loop|1
     local.get $1
     i32.const 16
     i32.lt_u
     if
      local.get $0
      i32.const 4
      i32.shl
      local.get $1
      i32.add
      i32.const 2
      i32.shl
      i32.const 40112
      i32.add
      i32.const 0
      i32.store $0 offset=96
      local.get $1
      i32.const 1
      i32.add
      local.set $1
      br $for-loop|1
     end
    end
    local.get $0
    i32.const 1
    i32.add
    local.set $0
    br $for-loop|0
   end
  end
  i32.const 40112
  i32.const 41684
  memory.size $0
  i64.extend_i32_s
  i64.const 16
  i64.shl
  call $~lib/rt/tlsf/addMemory
  i32.const 40112
  global.set $~lib/rt/tlsf/ROOT
 )
 (func $~lib/rt/itcms/step (result i32)
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  block $break|0
   block $case2|0
    block $case1|0
     block $case0|0
      global.get $~lib/rt/itcms/state
      br_table $case0|0 $case1|0 $case2|0 $break|0
     end
     i32.const 1
     global.set $~lib/rt/itcms/state
     i32.const 0
     global.set $~lib/rt/itcms/visitCount
     call $~lib/rt/itcms/visitRoots
     global.get $~lib/rt/itcms/toSpace
     global.set $~lib/rt/itcms/iter
     global.get $~lib/rt/itcms/visitCount
     return
    end
    global.get $~lib/rt/itcms/white
    i32.eqz
    local.set $1
    global.get $~lib/rt/itcms/iter
    i32.load $0 offset=4
    i32.const -4
    i32.and
    local.set $0
    loop $while-continue|1
     local.get $0
     global.get $~lib/rt/itcms/toSpace
     i32.ne
     if
      local.get $0
      global.set $~lib/rt/itcms/iter
      local.get $1
      local.get $0
      i32.load $0 offset=4
      i32.const 3
      i32.and
      i32.ne
      if
       local.get $0
       local.get $0
       i32.load $0 offset=4
       i32.const -4
       i32.and
       local.get $1
       i32.or
       i32.store $0 offset=4
       i32.const 0
       global.set $~lib/rt/itcms/visitCount
       local.get $0
       i32.const 20
       i32.add
       call $~lib/rt/__visit_members
       global.get $~lib/rt/itcms/visitCount
       return
      end
      local.get $0
      i32.load $0 offset=4
      i32.const -4
      i32.and
      local.set $0
      br $while-continue|1
     end
    end
    i32.const 0
    global.set $~lib/rt/itcms/visitCount
    call $~lib/rt/itcms/visitRoots
    global.get $~lib/rt/itcms/toSpace
    global.get $~lib/rt/itcms/iter
    i32.load $0 offset=4
    i32.const -4
    i32.and
    i32.eq
    if
     global.get $~lib/memory/__stack_pointer
     local.set $0
     loop $while-continue|0
      local.get $0
      i32.const 40100
      i32.lt_u
      if
       local.get $0
       i32.load $0
       local.tee $2
       if
        local.get $2
        call $byn-split-outlined-A$~lib/rt/itcms/__visit
       end
       local.get $0
       i32.const 4
       i32.add
       local.set $0
       br $while-continue|0
      end
     end
     global.get $~lib/rt/itcms/iter
     i32.load $0 offset=4
     i32.const -4
     i32.and
     local.set $0
     loop $while-continue|2
      local.get $0
      global.get $~lib/rt/itcms/toSpace
      i32.ne
      if
       local.get $1
       local.get $0
       i32.load $0 offset=4
       i32.const 3
       i32.and
       i32.ne
       if
        local.get $0
        local.get $0
        i32.load $0 offset=4
        i32.const -4
        i32.and
        local.get $1
        i32.or
        i32.store $0 offset=4
        local.get $0
        i32.const 20
        i32.add
        call $~lib/rt/__visit_members
       end
       local.get $0
       i32.load $0 offset=4
       i32.const -4
       i32.and
       local.set $0
       br $while-continue|2
      end
     end
     global.get $~lib/rt/itcms/fromSpace
     local.set $0
     global.get $~lib/rt/itcms/toSpace
     global.set $~lib/rt/itcms/fromSpace
     local.get $0
     global.set $~lib/rt/itcms/toSpace
     local.get $1
     global.set $~lib/rt/itcms/white
     local.get $0
     i32.load $0 offset=4
     i32.const -4
     i32.and
     global.set $~lib/rt/itcms/iter
     i32.const 2
     global.set $~lib/rt/itcms/state
    end
    global.get $~lib/rt/itcms/visitCount
    return
   end
   global.get $~lib/rt/itcms/iter
   local.tee $0
   global.get $~lib/rt/itcms/toSpace
   i32.ne
   if
    local.get $0
    i32.load $0 offset=4
    local.tee $1
    i32.const -4
    i32.and
    global.set $~lib/rt/itcms/iter
    global.get $~lib/rt/itcms/white
    i32.eqz
    local.get $1
    i32.const 3
    i32.and
    i32.ne
    if
     i32.const 0
     i32.const 1120
     i32.const 229
     i32.const 20
     call $~lib/builtins/abort
     unreachable
    end
    local.get $0
    i32.const 40100
    i32.lt_u
    if
     local.get $0
     i32.const 0
     i32.store $0 offset=4
     local.get $0
     i32.const 0
     i32.store $0 offset=8
    else
     global.get $~lib/rt/itcms/total
     local.get $0
     i32.load $0
     i32.const -4
     i32.and
     i32.const 4
     i32.add
     i32.sub
     global.set $~lib/rt/itcms/total
     local.get $0
     i32.const 4
     i32.add
     local.tee $0
     i32.const 40100
     i32.ge_u
     if
      global.get $~lib/rt/tlsf/ROOT
      i32.eqz
      if
       call $~lib/rt/tlsf/initialize
      end
      global.get $~lib/rt/tlsf/ROOT
      local.set $1
      local.get $0
      i32.const 4
      i32.sub
      local.set $2
      local.get $0
      i32.const 15
      i32.and
      i32.const 1
      local.get $0
      select
      if (result i32)
       i32.const 1
      else
       local.get $2
       i32.load $0
       i32.const 1
       i32.and
      end
      if
       i32.const 0
       i32.const 1392
       i32.const 560
       i32.const 3
       call $~lib/builtins/abort
       unreachable
      end
      local.get $2
      local.get $2
      i32.load $0
      i32.const 1
      i32.or
      i32.store $0
      local.get $1
      local.get $2
      call $~lib/rt/tlsf/insertBlock
     end
    end
    i32.const 10
    return
   end
   global.get $~lib/rt/itcms/toSpace
   local.tee $0
   local.get $0
   i32.store $0 offset=4
   local.get $0
   local.get $0
   i32.store $0 offset=8
   i32.const 0
   global.set $~lib/rt/itcms/state
  end
  i32.const 0
 )
 (func $~lib/rt/tlsf/searchBlock (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  local.get $1
  i32.const 256
  i32.lt_u
  if (result i32)
   local.get $1
   i32.const 4
   i32.shr_u
  else
   i32.const 31
   local.get $1
   i32.const 1
   i32.const 27
   local.get $1
   i32.clz
   i32.sub
   i32.shl
   i32.add
   i32.const 1
   i32.sub
   local.get $1
   local.get $1
   i32.const 536870910
   i32.lt_u
   select
   local.tee $1
   i32.clz
   i32.sub
   local.tee $3
   i32.const 7
   i32.sub
   local.set $2
   local.get $1
   local.get $3
   i32.const 4
   i32.sub
   i32.shr_u
   i32.const 16
   i32.xor
  end
  local.tee $1
  i32.const 16
  i32.lt_u
  local.get $2
  i32.const 23
  i32.lt_u
  i32.and
  i32.eqz
  if
   i32.const 0
   i32.const 1392
   i32.const 330
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $0
  local.get $2
  i32.const 2
  i32.shl
  i32.add
  i32.load $0 offset=4
  i32.const -1
  local.get $1
  i32.shl
  i32.and
  local.tee $1
  if (result i32)
   local.get $0
   local.get $1
   i32.ctz
   local.get $2
   i32.const 4
   i32.shl
   i32.add
   i32.const 2
   i32.shl
   i32.add
   i32.load $0 offset=96
  else
   local.get $0
   i32.load $0
   i32.const -1
   local.get $2
   i32.const 1
   i32.add
   i32.shl
   i32.and
   local.tee $1
   if (result i32)
    local.get $0
    local.get $1
    i32.ctz
    local.tee $1
    i32.const 2
    i32.shl
    i32.add
    i32.load $0 offset=4
    local.tee $2
    i32.eqz
    if
     i32.const 0
     i32.const 1392
     i32.const 343
     i32.const 18
     call $~lib/builtins/abort
     unreachable
    end
    local.get $0
    local.get $2
    i32.ctz
    local.get $1
    i32.const 4
    i32.shl
    i32.add
    i32.const 2
    i32.shl
    i32.add
    i32.load $0 offset=96
   else
    i32.const 0
   end
  end
 )
 (func $~lib/rt/itcms/__new (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  local.get $0
  i32.const 1073741804
  i32.ge_u
  if
   i32.const 1056
   i32.const 1120
   i32.const 261
   i32.const 31
   call $~lib/builtins/abort
   unreachable
  end
  global.get $~lib/rt/itcms/total
  global.get $~lib/rt/itcms/threshold
  i32.ge_u
  if
   block $__inlined_func$~lib/rt/itcms/interrupt
    i32.const 2048
    local.set $2
    loop $do-loop|0
     local.get $2
     call $~lib/rt/itcms/step
     i32.sub
     local.set $2
     global.get $~lib/rt/itcms/state
     i32.eqz
     if
      global.get $~lib/rt/itcms/total
      i64.extend_i32_u
      i64.const 200
      i64.mul
      i64.const 100
      i64.div_u
      i32.wrap_i64
      i32.const 1024
      i32.add
      global.set $~lib/rt/itcms/threshold
      br $__inlined_func$~lib/rt/itcms/interrupt
     end
     local.get $2
     i32.const 0
     i32.gt_s
     br_if $do-loop|0
    end
    global.get $~lib/rt/itcms/total
    local.tee $2
    local.get $2
    global.get $~lib/rt/itcms/threshold
    i32.sub
    i32.const 1024
    i32.lt_u
    i32.const 10
    i32.shl
    i32.add
    global.set $~lib/rt/itcms/threshold
   end
  end
  global.get $~lib/rt/tlsf/ROOT
  i32.eqz
  if
   call $~lib/rt/tlsf/initialize
  end
  global.get $~lib/rt/tlsf/ROOT
  local.set $4
  local.get $0
  i32.const 16
  i32.add
  local.tee $2
  i32.const 1073741820
  i32.gt_u
  if
   i32.const 1056
   i32.const 1392
   i32.const 459
   i32.const 29
   call $~lib/builtins/abort
   unreachable
  end
  local.get $4
  i32.const 12
  local.get $2
  i32.const 19
  i32.add
  i32.const -16
  i32.and
  i32.const 4
  i32.sub
  local.get $2
  i32.const 12
  i32.le_u
  select
  local.tee $5
  call $~lib/rt/tlsf/searchBlock
  local.tee $2
  i32.eqz
  if
   memory.size $0
   local.tee $2
   i32.const 4
   local.get $4
   i32.load $0 offset=1568
   local.get $2
   i32.const 16
   i32.shl
   i32.const 4
   i32.sub
   i32.ne
   i32.shl
   local.get $5
   i32.const 1
   i32.const 27
   local.get $5
   i32.clz
   i32.sub
   i32.shl
   i32.const 1
   i32.sub
   i32.add
   local.get $5
   local.get $5
   i32.const 536870910
   i32.lt_u
   select
   i32.add
   i32.const 65535
   i32.add
   i32.const -65536
   i32.and
   i32.const 16
   i32.shr_u
   local.tee $3
   local.get $2
   local.get $3
   i32.gt_s
   select
   memory.grow $0
   i32.const 0
   i32.lt_s
   if
    local.get $3
    memory.grow $0
    i32.const 0
    i32.lt_s
    if
     unreachable
    end
   end
   local.get $4
   local.get $2
   i32.const 16
   i32.shl
   memory.size $0
   i64.extend_i32_s
   i64.const 16
   i64.shl
   call $~lib/rt/tlsf/addMemory
   local.get $4
   local.get $5
   call $~lib/rt/tlsf/searchBlock
   local.tee $2
   i32.eqz
   if
    i32.const 0
    i32.const 1392
    i32.const 497
    i32.const 16
    call $~lib/builtins/abort
    unreachable
   end
  end
  local.get $5
  local.get $2
  i32.load $0
  i32.const -4
  i32.and
  i32.gt_u
  if
   i32.const 0
   i32.const 1392
   i32.const 499
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $4
  local.get $2
  call $~lib/rt/tlsf/removeBlock
  local.get $2
  i32.load $0
  local.set $3
  local.get $5
  i32.const 4
  i32.add
  i32.const 15
  i32.and
  if
   i32.const 0
   i32.const 1392
   i32.const 357
   i32.const 14
   call $~lib/builtins/abort
   unreachable
  end
  local.get $3
  i32.const -4
  i32.and
  local.get $5
  i32.sub
  local.tee $6
  i32.const 16
  i32.ge_u
  if
   local.get $2
   local.get $5
   local.get $3
   i32.const 2
   i32.and
   i32.or
   i32.store $0
   local.get $2
   i32.const 4
   i32.add
   local.get $5
   i32.add
   local.tee $3
   local.get $6
   i32.const 4
   i32.sub
   i32.const 1
   i32.or
   i32.store $0
   local.get $4
   local.get $3
   call $~lib/rt/tlsf/insertBlock
  else
   local.get $2
   local.get $3
   i32.const -2
   i32.and
   i32.store $0
   local.get $2
   i32.const 4
   i32.add
   local.get $2
   i32.load $0
   i32.const -4
   i32.and
   i32.add
   local.tee $3
   local.get $3
   i32.load $0
   i32.const -3
   i32.and
   i32.store $0
  end
  local.get $2
  local.get $1
  i32.store $0 offset=12
  local.get $2
  local.get $0
  i32.store $0 offset=16
  global.get $~lib/rt/itcms/fromSpace
  local.tee $1
  i32.load $0 offset=8
  local.set $3
  local.get $2
  local.get $1
  global.get $~lib/rt/itcms/white
  i32.or
  i32.store $0 offset=4
  local.get $2
  local.get $3
  i32.store $0 offset=8
  local.get $3
  local.get $2
  local.get $3
  i32.load $0 offset=4
  i32.const 3
  i32.and
  i32.or
  i32.store $0 offset=4
  local.get $1
  local.get $2
  i32.store $0 offset=8
  global.get $~lib/rt/itcms/total
  local.get $2
  i32.load $0
  i32.const -4
  i32.and
  i32.const 4
  i32.add
  i32.add
  global.set $~lib/rt/itcms/total
  local.get $2
  i32.const 20
  i32.add
  local.tee $1
  i32.const 0
  local.get $0
  memory.fill $0
  local.get $1
 )
 (func $~lib/util/uri/decode (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (local $7 i32)
  (local $8 i32)
  (local $9 i32)
  local.get $1
  i32.eqz
  if
   local.get $0
   return
  end
  local.get $1
  i32.const 1
  i32.shl
  i32.const 2
  call $~lib/rt/itcms/__new
  local.set $3
  loop $while-continue|0
   local.get $1
   local.get $2
   i32.gt_u
   if
    block $while-break|0
     local.get $2
     local.set $4
     loop $while-continue|1
      local.get $1
      local.get $2
      i32.gt_u
      if (result i32)
       local.get $0
       local.get $2
       i32.const 1
       i32.shl
       i32.add
       i32.load16_u $0
       local.tee $8
       i32.const 37
       i32.ne
      else
       i32.const 0
      end
      if
       local.get $2
       i32.const 1
       i32.add
       local.set $2
       br $while-continue|1
      end
     end
     local.get $2
     local.get $4
     i32.gt_u
     if
      local.get $3
      local.get $6
      i32.add
      local.get $0
      local.get $4
      i32.const 1
      i32.shl
      i32.add
      local.get $2
      local.get $4
      i32.sub
      i32.const 1
      i32.shl
      local.tee $4
      memory.copy $0 $0
      local.get $4
      local.get $6
      i32.add
      local.set $6
      local.get $1
      local.get $2
      i32.le_u
      br_if $while-break|0
     end
     local.get $8
     i32.const 37
     i32.ne
     local.get $2
     i32.const 2
     i32.add
     local.get $1
     i32.ge_u
     i32.or
     if (result i32)
      i32.const 1
     else
      local.get $2
      i32.const 1
      i32.add
      i32.const 1
      i32.shl
      local.get $0
      i32.add
      local.tee $4
      i32.load16_u $0
      local.set $7
      local.get $4
      i32.load16_u $0 offset=2
      local.set $4
      local.get $7
      i32.const 32
      i32.or
      i32.const 97
      i32.sub
      i32.const 6
      i32.lt_u
      local.get $7
      i32.const 48
      i32.sub
      i32.const 10
      i32.lt_u
      i32.or
      if (result i32)
       local.get $4
       i32.const 32
       i32.or
       i32.const 97
       i32.sub
       i32.const 6
       i32.lt_u
       local.get $4
       i32.const 48
       i32.sub
       i32.const 10
       i32.lt_u
       i32.or
      else
       i32.const 0
      end
      if (result i32)
       local.get $4
       i32.const 32
       i32.or
       i32.const 39
       i32.rem_u
       i32.const 9
       i32.sub
       local.get $7
       i32.const 32
       i32.or
       i32.const 39
       i32.rem_u
       i32.const 9
       i32.sub
       i32.const 4
       i32.shl
       i32.or
      else
       i32.const -1
      end
      local.tee $8
      i32.const -1
      i32.eq
     end
     if
      i32.const 1456
      i32.const 1504
      i32.const 164
      i32.const 7
      call $~lib/builtins/abort
      unreachable
     end
     local.get $2
     i32.const 3
     i32.add
     local.set $2
     local.get $8
     i32.const 128
     i32.lt_u
     if
      local.get $8
      i32.const 35
      i32.sub
      i32.const 30
      i32.lt_u
      if (result i32)
       local.get $8
       i32.const 1513
       i32.add
       i32.load8_u $0
      else
       i32.const 0
      end
      if
       i32.const 37
       local.set $8
       local.get $2
       i32.const 2
       i32.sub
       local.set $2
      end
     else
      i32.const 1
      local.get $8
      i32.const 24
      i32.shl
      i32.const -1
      i32.xor
      i32.clz
      i32.const 0
      local.get $8
      i32.const 192
      i32.sub
      i32.const 56
      i32.lt_u
      select
      local.tee $7
      i32.const 17
      i32.mul
      i32.const 2
      i32.shr_u
      i32.const 1
      i32.sub
      i32.shl
      local.set $4
      local.get $8
      i32.const 128
      local.get $7
      i32.shr_u
      i32.const 1
      i32.sub
      i32.const 0
      local.get $7
      select
      i32.and
      local.set $8
      loop $while-continue|2
       local.get $7
       i32.const 1
       i32.sub
       local.tee $7
       if
        block $while-break|2
         local.get $2
         i32.const 2
         i32.add
         local.get $1
         i32.ge_u
         if (result i32)
          i32.const 1
         else
          local.get $0
          local.get $2
          i32.const 1
          i32.shl
          i32.add
          i32.load16_u $0
          i32.const 37
          i32.ne
         end
         if (result i32)
          i32.const 1
         else
          local.get $2
          i32.const 1
          i32.add
          i32.const 1
          i32.shl
          local.get $0
          i32.add
          local.tee $5
          i32.load16_u $0
          local.set $9
          local.get $5
          i32.load16_u $0 offset=2
          local.set $5
          local.get $9
          i32.const 32
          i32.or
          i32.const 97
          i32.sub
          i32.const 6
          i32.lt_u
          local.get $9
          i32.const 48
          i32.sub
          i32.const 10
          i32.lt_u
          i32.or
          if (result i32)
           local.get $5
           i32.const 32
           i32.or
           i32.const 97
           i32.sub
           i32.const 6
           i32.lt_u
           local.get $5
           i32.const 48
           i32.sub
           i32.const 10
           i32.lt_u
           i32.or
          else
           i32.const 0
          end
          if (result i32)
           local.get $5
           i32.const 32
           i32.or
           i32.const 39
           i32.rem_u
           i32.const 9
           i32.sub
           local.get $9
           i32.const 32
           i32.or
           i32.const 39
           i32.rem_u
           i32.const 9
           i32.sub
           i32.const 4
           i32.shl
           i32.or
          else
           i32.const -1
          end
          local.tee $5
          i32.const -1
          i32.eq
         end
         if
          i32.const 1456
          i32.const 1504
          i32.const 187
          i32.const 11
          call $~lib/builtins/abort
          unreachable
         end
         local.get $2
         i32.const 3
         i32.add
         local.set $2
         local.get $5
         i32.const 192
         i32.and
         i32.const 128
         i32.ne
         if
          i32.const 0
          local.set $8
          br $while-break|2
         end
         local.get $5
         i32.const 63
         i32.and
         local.get $8
         i32.const 6
         i32.shl
         i32.or
         local.set $8
         br $while-continue|2
        end
       end
      end
      local.get $8
      i32.const 57344
      i32.lt_u
      local.get $8
      i32.const 55296
      i32.ge_u
      i32.and
      local.get $4
      i32.const -1
      i32.eq
      local.get $4
      local.get $8
      i32.gt_u
      i32.or
      local.get $8
      i32.const 1114111
      i32.gt_u
      i32.or
      i32.or
      if
       i32.const 1456
       i32.const 1504
       i32.const 199
       i32.const 9
       call $~lib/builtins/abort
       unreachable
      end
      local.get $8
      i32.const 65536
      i32.ge_u
      if
       local.get $3
       local.get $6
       i32.add
       local.get $8
       i32.const 65536
       i32.sub
       local.tee $8
       i32.const 10
       i32.shr_u
       i32.const 55296
       i32.or
       local.get $8
       i32.const 1023
       i32.and
       i32.const 56320
       i32.or
       i32.const 16
       i32.shl
       i32.or
       i32.store $0
       local.get $6
       i32.const 4
       i32.add
       local.set $6
       br $while-continue|0
      end
     end
     local.get $3
     local.get $6
     i32.add
     local.get $8
     i32.store16 $0
     local.get $6
     i32.const 2
     i32.add
     local.set $6
     br $while-continue|0
    end
   end
  end
  local.get $1
  i32.const 1
  i32.shl
  local.get $6
  i32.lt_u
  if
   i32.const 0
   i32.const 1504
   i32.const 216
   i32.const 3
   call $~lib/builtins/abort
   unreachable
  end
  local.get $1
  i32.const 1
  i32.shl
  local.get $6
  i32.gt_u
  if
   block $__inlined_func$~lib/rt/itcms/__renew
    local.get $6
    local.get $3
    i32.const 20
    i32.sub
    local.tee $1
    i32.load $0
    i32.const -4
    i32.and
    i32.const 16
    i32.sub
    i32.le_u
    if
     local.get $1
     local.get $6
     i32.store $0 offset=16
     local.get $3
     local.set $0
     br $__inlined_func$~lib/rt/itcms/__renew
    end
    local.get $6
    local.get $1
    i32.load $0 offset=12
    call $~lib/rt/itcms/__new
    local.tee $0
    local.get $3
    local.get $6
    local.get $1
    i32.load $0 offset=16
    local.tee $1
    local.get $1
    local.get $6
    i32.gt_u
    select
    memory.copy $0 $0
   end
  else
   local.get $3
   local.set $0
  end
  local.get $0
 )
 (func $~lib/rt/itcms/__pin (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  local.get $0
  if
   local.get $0
   i32.const 20
   i32.sub
   local.tee $1
   i32.load $0 offset=4
   i32.const 3
   i32.and
   i32.const 3
   i32.eq
   if
    i32.const 7200
    i32.const 1120
    i32.const 338
    i32.const 7
    call $~lib/builtins/abort
    unreachable
   end
   local.get $1
   call $~lib/rt/itcms/Object#unlink
   global.get $~lib/rt/itcms/pinSpace
   local.tee $3
   i32.load $0 offset=8
   local.set $2
   local.get $1
   local.get $3
   i32.const 3
   i32.or
   i32.store $0 offset=4
   local.get $1
   local.get $2
   i32.store $0 offset=8
   local.get $2
   local.get $1
   local.get $2
   i32.load $0 offset=4
   i32.const 3
   i32.and
   i32.or
   i32.store $0 offset=4
   local.get $3
   local.get $1
   i32.store $0 offset=8
  end
  local.get $0
 )
 (func $~lib/rt/itcms/__unpin (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  local.get $0
  i32.eqz
  if
   return
  end
  local.get $0
  i32.const 20
  i32.sub
  local.tee $1
  i32.load $0 offset=4
  i32.const 3
  i32.and
  i32.const 3
  i32.ne
  if
   i32.const 7264
   i32.const 1120
   i32.const 352
   i32.const 5
   call $~lib/builtins/abort
   unreachable
  end
  global.get $~lib/rt/itcms/state
  i32.const 1
  i32.eq
  if
   local.get $1
   call $~lib/rt/itcms/Object#makeGray
  else
   local.get $1
   call $~lib/rt/itcms/Object#unlink
   global.get $~lib/rt/itcms/fromSpace
   local.tee $0
   i32.load $0 offset=8
   local.set $2
   local.get $1
   local.get $0
   global.get $~lib/rt/itcms/white
   i32.or
   i32.store $0 offset=4
   local.get $1
   local.get $2
   i32.store $0 offset=8
   local.get $2
   local.get $1
   local.get $2
   i32.load $0 offset=4
   i32.const 3
   i32.and
   i32.or
   i32.store $0 offset=4
   local.get $0
   local.get $1
   i32.store $0 offset=8
  end
 )
 (func $~lib/rt/itcms/__collect
  global.get $~lib/rt/itcms/state
  i32.const 0
  i32.gt_s
  if
   loop $while-continue|0
    global.get $~lib/rt/itcms/state
    if
     call $~lib/rt/itcms/step
     drop
     br $while-continue|0
    end
   end
  end
  call $~lib/rt/itcms/step
  drop
  loop $while-continue|1
   global.get $~lib/rt/itcms/state
   if
    call $~lib/rt/itcms/step
    drop
    br $while-continue|1
   end
  end
  global.get $~lib/rt/itcms/total
  i64.extend_i32_u
  i64.const 200
  i64.mul
  i64.const 100
  i64.div_u
  i32.wrap_i64
  i32.const 1024
  i32.add
  global.set $~lib/rt/itcms/threshold
 )
 (func $~lib/rt/__visit_members (param $0 i32)
  block $invalid
   block $~lib/arraybuffer/ArrayBufferView
    block $~lib/string/String
     block $~lib/arraybuffer/ArrayBuffer
      block $~lib/object/Object
       local.get $0
       i32.const 8
       i32.sub
       i32.load $0
       br_table $~lib/object/Object $~lib/arraybuffer/ArrayBuffer $~lib/string/String $~lib/arraybuffer/ArrayBufferView $invalid
      end
      return
     end
     return
    end
    return
   end
   local.get $0
   i32.load $0
   local.tee $0
   if
    local.get $0
    call $byn-split-outlined-A$~lib/rt/itcms/__visit
   end
   return
  end
  unreachable
 )
 (func $~start
  memory.size $0
  i32.const 16
  i32.shl
  i32.const 40100
  i32.sub
  i32.const 1
  i32.shr_u
  global.set $~lib/rt/itcms/threshold
  i32.const 1172
  i32.const 1168
  i32.store $0
  i32.const 1176
  i32.const 1168
  i32.store $0
  i32.const 1168
  global.set $~lib/rt/itcms/pinSpace
  i32.const 1204
  i32.const 1200
  i32.store $0
  i32.const 1208
  i32.const 1200
  i32.store $0
  i32.const 1200
  global.set $~lib/rt/itcms/toSpace
  i32.const 1348
  i32.const 1344
  i32.store $0
  i32.const 1352
  i32.const 1344
  i32.store $0
  i32.const 1344
  global.set $~lib/rt/itcms/fromSpace
 )
 (func $~lib/string/String.__eq (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  global.get $~lib/memory/__stack_pointer
  i32.const 8
  i32.sub
  global.set $~lib/memory/__stack_pointer
  global.get $~lib/memory/__stack_pointer
  i32.const 7332
  i32.lt_s
  if
   i32.const 40128
   i32.const 40176
   i32.const 1
   i32.const 1
   call $~lib/builtins/abort
   unreachable
  end
  global.get $~lib/memory/__stack_pointer
  i64.const 0
  i64.store $0
  local.get $0
  local.get $1
  i32.eq
  if
   global.get $~lib/memory/__stack_pointer
   i32.const 8
   i32.add
   global.set $~lib/memory/__stack_pointer
   i32.const 1
   return
  end
  block $folding-inner0
   local.get $1
   i32.eqz
   local.get $0
   i32.eqz
   i32.or
   br_if $folding-inner0
   global.get $~lib/memory/__stack_pointer
   local.tee $2
   local.get $0
   i32.store $0
   local.get $0
   i32.const 20
   i32.sub
   i32.load $0 offset=16
   i32.const 1
   i32.shr_u
   local.set $3
   local.get $2
   local.get $1
   i32.store $0
   local.get $3
   local.get $1
   i32.const 20
   i32.sub
   i32.load $0 offset=16
   i32.const 1
   i32.shr_u
   i32.ne
   br_if $folding-inner0
   global.get $~lib/memory/__stack_pointer
   local.tee $2
   local.get $0
   i32.store $0
   local.get $2
   local.get $1
   i32.store $0 offset=4
   block $__inlined_func$~lib/util/string/compareImpl (result i32)
    local.get $0
    local.tee $2
    i32.const 7
    i32.and
    local.get $1
    i32.const 7
    i32.and
    i32.or
    i32.eqz
    local.get $3
    local.tee $0
    i32.const 4
    i32.ge_u
    i32.and
    if
     loop $do-loop|0
      local.get $2
      i64.load $0
      local.get $1
      i64.load $0
      i64.eq
      if
       local.get $2
       i32.const 8
       i32.add
       local.set $2
       local.get $1
       i32.const 8
       i32.add
       local.set $1
       local.get $0
       i32.const 4
       i32.sub
       local.tee $0
       i32.const 4
       i32.ge_u
       br_if $do-loop|0
      end
     end
    end
    loop $while-continue|1
     local.get $0
     local.tee $3
     i32.const 1
     i32.sub
     local.set $0
     local.get $3
     if
      local.get $1
      i32.load16_u $0
      local.tee $3
      local.get $2
      i32.load16_u $0
      local.tee $4
      i32.ne
      if
       local.get $4
       local.get $3
       i32.sub
       br $__inlined_func$~lib/util/string/compareImpl
      end
      local.get $2
      i32.const 2
      i32.add
      local.set $2
      local.get $1
      i32.const 2
      i32.add
      local.set $1
      br $while-continue|1
     end
    end
    i32.const 0
   end
   local.set $0
   global.get $~lib/memory/__stack_pointer
   i32.const 8
   i32.add
   global.set $~lib/memory/__stack_pointer
   local.get $0
   i32.eqz
   return
  end
  global.get $~lib/memory/__stack_pointer
  i32.const 8
  i32.add
  global.set $~lib/memory/__stack_pointer
  i32.const 0
 )
 (func $~lib/string/String.__concat (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  global.get $~lib/memory/__stack_pointer
  i32.const 8
  i32.sub
  global.set $~lib/memory/__stack_pointer
  block $folding-inner0
   global.get $~lib/memory/__stack_pointer
   i32.const 7332
   i32.lt_s
   br_if $folding-inner0
   global.get $~lib/memory/__stack_pointer
   local.tee $1
   i64.const 0
   i64.store $0
   local.get $1
   i32.const 1600
   i32.store $0
   local.get $1
   local.get $0
   i32.store $0 offset=4
   local.get $1
   i32.const 8
   i32.sub
   global.set $~lib/memory/__stack_pointer
   global.get $~lib/memory/__stack_pointer
   i32.const 7332
   i32.lt_s
   br_if $folding-inner0
   global.get $~lib/memory/__stack_pointer
   local.tee $1
   i64.const 0
   i64.store $0
   local.get $1
   i32.const 1600
   i32.store $0
   i32.const 1596
   i32.load $0
   i32.const -2
   i32.and
   local.set $2
   local.get $1
   local.get $0
   i32.store $0
   block $__inlined_func$~lib/string/String#concat
    local.get $0
    i32.const 20
    i32.sub
    i32.load $0 offset=16
    i32.const -2
    i32.and
    local.tee $3
    local.get $2
    i32.add
    local.tee $1
    i32.eqz
    if
     global.get $~lib/memory/__stack_pointer
     i32.const 8
     i32.add
     global.set $~lib/memory/__stack_pointer
     i32.const 3040
     local.set $1
     br $__inlined_func$~lib/string/String#concat
    end
    global.get $~lib/memory/__stack_pointer
    local.get $1
    i32.const 2
    call $~lib/rt/itcms/__new
    local.tee $1
    i32.store $0 offset=4
    local.get $1
    i32.const 1600
    local.get $2
    memory.copy $0 $0
    local.get $1
    local.get $2
    i32.add
    local.get $0
    local.get $3
    memory.copy $0 $0
    global.get $~lib/memory/__stack_pointer
    i32.const 8
    i32.add
    global.set $~lib/memory/__stack_pointer
   end
   global.get $~lib/memory/__stack_pointer
   i32.const 8
   i32.add
   global.set $~lib/memory/__stack_pointer
   local.get $1
   return
  end
  i32.const 40128
  i32.const 40176
  i32.const 1
  i32.const 1
  call $~lib/builtins/abort
  unreachable
 )
 (func $~lib/util/string/strtol<f64> (param $0 i32) (result f64)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 f64)
  (local $5 f64)
  (local $6 i32)
  global.get $~lib/memory/__stack_pointer
  i32.const 4
  i32.sub
  global.set $~lib/memory/__stack_pointer
  global.get $~lib/memory/__stack_pointer
  i32.const 7332
  i32.lt_s
  if
   i32.const 40128
   i32.const 40176
   i32.const 1
   i32.const 1
   call $~lib/builtins/abort
   unreachable
  end
  global.get $~lib/memory/__stack_pointer
  local.tee $1
  i32.const 0
  i32.store $0
  local.get $1
  local.get $0
  i32.store $0
  block $folding-inner0
   local.get $0
   i32.const 20
   i32.sub
   i32.load $0 offset=16
   i32.const 1
   i32.shr_u
   local.tee $1
   i32.eqz
   br_if $folding-inner0
   local.get $0
   local.tee $2
   i32.load16_u $0
   local.set $0
   loop $while-continue|0
    block $__inlined_func$~lib/util/string/isSpace (result i32)
     local.get $0
     i32.const 128
     i32.or
     i32.const 160
     i32.eq
     local.get $0
     i32.const 9
     i32.sub
     i32.const 4
     i32.le_u
     i32.or
     local.get $0
     i32.const 5760
     i32.lt_u
     br_if $__inlined_func$~lib/util/string/isSpace
     drop
     i32.const 1
     local.get $0
     i32.const -8192
     i32.add
     i32.const 10
     i32.le_u
     br_if $__inlined_func$~lib/util/string/isSpace
     drop
     block $break|0
      block $case0|0
       local.get $0
       i32.const 5760
       i32.eq
       br_if $case0|0
       local.get $0
       i32.const 8232
       i32.eq
       br_if $case0|0
       local.get $0
       i32.const 8233
       i32.eq
       br_if $case0|0
       local.get $0
       i32.const 8239
       i32.eq
       br_if $case0|0
       local.get $0
       i32.const 8287
       i32.eq
       br_if $case0|0
       local.get $0
       i32.const 12288
       i32.eq
       br_if $case0|0
       local.get $0
       i32.const 65279
       i32.eq
       br_if $case0|0
       br $break|0
      end
      i32.const 1
      br $__inlined_func$~lib/util/string/isSpace
     end
     i32.const 0
    end
    if
     local.get $2
     i32.const 2
     i32.add
     local.tee $2
     i32.load16_u $0
     local.set $0
     local.get $1
     i32.const 1
     i32.sub
     local.set $1
     br $while-continue|0
    end
   end
   f64.const 1
   local.set $4
   local.get $0
   i32.const 43
   i32.eq
   local.get $0
   i32.const 45
   i32.eq
   i32.or
   if (result i32)
    local.get $1
    i32.const 1
    i32.sub
    local.tee $1
    i32.eqz
    br_if $folding-inner0
    f64.const -1
    f64.const 1
    local.get $0
    i32.const 45
    i32.eq
    select
    local.set $4
    local.get $2
    i32.const 2
    i32.add
    local.tee $2
    i32.load16_u $0
   else
    local.get $0
   end
   i32.const 48
   i32.eq
   local.get $1
   i32.const 2
   i32.gt_s
   i32.and
   if
    block $break|1
     block $case2|1
      block $case1|1
       local.get $2
       i32.load16_u $0 offset=2
       i32.const 32
       i32.or
       local.tee $0
       i32.const 98
       i32.ne
       if
        local.get $0
        i32.const 111
        i32.eq
        br_if $case1|1
        local.get $0
        i32.const 120
        i32.eq
        br_if $case2|1
        br $break|1
       end
       local.get $2
       i32.const 4
       i32.add
       local.set $2
       local.get $1
       i32.const 2
       i32.sub
       local.set $1
       i32.const 2
       local.set $3
       br $break|1
      end
      local.get $2
      i32.const 4
      i32.add
      local.set $2
      local.get $1
      i32.const 2
      i32.sub
      local.set $1
      i32.const 8
      local.set $3
      br $break|1
     end
     local.get $2
     i32.const 4
     i32.add
     local.set $2
     local.get $1
     i32.const 2
     i32.sub
     local.set $1
     i32.const 16
     local.set $3
    end
   end
   local.get $3
   i32.const 10
   local.get $3
   select
   local.set $3
   local.get $1
   i32.const 1
   i32.sub
   local.set $6
   loop $while-continue|2
    local.get $1
    local.tee $0
    i32.const 1
    i32.sub
    local.set $1
    local.get $0
    if
     block $while-break|2
      local.get $3
      local.get $2
      i32.load16_u $0
      local.tee $0
      i32.const 48
      i32.sub
      i32.const 10
      i32.lt_u
      if (result i32)
       local.get $0
       i32.const 48
       i32.sub
      else
       local.get $0
       i32.const 65
       i32.sub
       i32.const 25
       i32.le_u
       if (result i32)
        local.get $0
        i32.const 55
        i32.sub
       else
        local.get $0
        i32.const 87
        i32.sub
        local.get $0
        local.get $0
        i32.const 97
        i32.sub
        i32.const 25
        i32.le_u
        select
       end
      end
      local.tee $0
      i32.le_u
      if
       local.get $1
       local.get $6
       i32.eq
       br_if $folding-inner0
       br $while-break|2
      end
      local.get $5
      local.get $3
      f64.convert_i32_s
      f64.mul
      local.get $0
      f64.convert_i32_u
      f64.add
      local.set $5
      local.get $2
      i32.const 2
      i32.add
      local.set $2
      br $while-continue|2
     end
    end
   end
   global.get $~lib/memory/__stack_pointer
   i32.const 4
   i32.add
   global.set $~lib/memory/__stack_pointer
   local.get $4
   local.get $5
   f64.mul
   return
  end
  global.get $~lib/memory/__stack_pointer
  i32.const 4
  i32.add
  global.set $~lib/memory/__stack_pointer
  f64.const nan:0x8000000000000
 )
 (func $assembly/index/index (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 f64)
  (local $6 i32)
  global.get $~lib/memory/__stack_pointer
  i32.const 24
  i32.sub
  global.set $~lib/memory/__stack_pointer
  block $folding-inner0
   global.get $~lib/memory/__stack_pointer
   i32.const 7332
   i32.lt_s
   br_if $folding-inner0
   global.get $~lib/memory/__stack_pointer
   local.tee $1
   i32.const 0
   i32.const 24
   memory.fill $0
   local.get $1
   local.get $0
   i32.store $0
   local.get $1
   i32.const 4
   i32.sub
   global.set $~lib/memory/__stack_pointer
   global.get $~lib/memory/__stack_pointer
   i32.const 7332
   i32.lt_s
   br_if $folding-inner0
   global.get $~lib/memory/__stack_pointer
   local.tee $2
   i32.const 0
   i32.store $0
   local.get $2
   local.get $0
   i32.store $0
   local.get $0
   local.get $0
   i32.const 20
   i32.sub
   i32.load $0 offset=16
   i32.const 1
   i32.shr_u
   call $~lib/util/uri/decode
   local.set $0
   global.get $~lib/memory/__stack_pointer
   i32.const 4
   i32.add
   global.set $~lib/memory/__stack_pointer
   local.get $1
   local.get $0
   i32.store $0 offset=4
   global.get $~lib/memory/__stack_pointer
   i32.const 1600
   i32.store $0 offset=8
   global.get $~lib/memory/__stack_pointer
   local.get $0
   i32.store $0
   global.get $~lib/memory/__stack_pointer
   i32.const 3040
   i32.store $0 offset=12
   local.get $0
   i32.const 3040
   call $~lib/string/String.__eq
   if
    global.get $~lib/memory/__stack_pointer
    local.tee $0
    i32.const 1600
    i32.store $0
    local.get $0
    i32.const 3072
    i32.store $0 offset=12
    local.get $0
    i32.const 3072
    call $~lib/string/String.__concat
    local.tee $0
    i32.store $0 offset=8
   else
    global.get $~lib/memory/__stack_pointer
    local.tee $1
    local.get $0
    i32.store $0
    local.get $1
    i32.const 3520
    i32.store $0 offset=12
    local.get $0
    i32.const 3520
    call $~lib/string/String.__eq
    if
     global.get $~lib/memory/__stack_pointer
     local.tee $0
     i32.const 1600
     i32.store $0
     local.get $0
     i32.const 3552
     i32.store $0 offset=12
     local.get $0
     i32.const 3552
     call $~lib/string/String.__concat
     local.tee $0
     i32.store $0 offset=8
    else
     global.get $~lib/memory/__stack_pointer
     local.tee $1
     local.get $0
     i32.store $0
     local.get $1
     i32.const 4768
     i32.store $0 offset=12
     local.get $0
     i32.const 4768
     call $~lib/string/String.__eq
     if
      global.get $~lib/memory/__stack_pointer
      local.tee $0
      i32.const 1600
      i32.store $0
      local.get $0
      i32.const 4816
      i32.store $0 offset=12
      local.get $0
      i32.const 4816
      call $~lib/string/String.__concat
      local.tee $0
      i32.store $0 offset=8
     else
      global.get $~lib/memory/__stack_pointer
      local.tee $1
      local.get $0
      i32.store $0
      local.get $1
      i32.const 7088
      i32.store $0 offset=12
      local.get $1
      i32.const 8
      i32.sub
      global.set $~lib/memory/__stack_pointer
      global.get $~lib/memory/__stack_pointer
      i32.const 7332
      i32.lt_s
      br_if $folding-inner0
      global.get $~lib/memory/__stack_pointer
      local.tee $1
      i64.const 0
      i64.store $0
      local.get $1
      local.get $0
      i32.store $0
      local.get $0
      i32.const 20
      i32.sub
      i32.load $0 offset=16
      i32.const 1
      i32.shr_u
      local.set $2
      local.get $1
      i32.const 7088
      i32.store $0
      block $__inlined_func$~lib/string/String#startsWith
       i32.const 7084
       i32.load $0
       i32.const 1
       i32.shr_u
       local.tee $1
       local.get $2
       i32.gt_s
       if
        global.get $~lib/memory/__stack_pointer
        i32.const 8
        i32.add
        global.set $~lib/memory/__stack_pointer
        i32.const 0
        local.set $1
        br $__inlined_func$~lib/string/String#startsWith
       end
       global.get $~lib/memory/__stack_pointer
       local.tee $2
       local.get $0
       i32.store $0
       local.get $2
       i32.const 7088
       i32.store $0 offset=4
       block $__inlined_func$~lib/util/string/compareImpl (result i32)
        local.get $0
        local.set $2
        i32.const 7088
        local.set $4
        local.get $0
        i32.const 7
        i32.and
        i32.eqz
        local.get $1
        i32.const 4
        i32.ge_u
        i32.and
        if
         loop $do-loop|0
          local.get $2
          i64.load $0
          local.get $4
          i64.load $0
          i64.eq
          if
           local.get $2
           i32.const 8
           i32.add
           local.set $2
           local.get $4
           i32.const 8
           i32.add
           local.set $4
           local.get $1
           i32.const 4
           i32.sub
           local.tee $1
           i32.const 4
           i32.ge_u
           br_if $do-loop|0
          end
         end
        end
        loop $while-continue|1
         local.get $1
         local.tee $3
         i32.const 1
         i32.sub
         local.set $1
         local.get $3
         if
          local.get $4
          i32.load16_u $0
          local.tee $3
          local.get $2
          i32.load16_u $0
          local.tee $6
          i32.ne
          if
           local.get $6
           local.get $3
           i32.sub
           br $__inlined_func$~lib/util/string/compareImpl
          end
          local.get $2
          i32.const 2
          i32.add
          local.set $2
          local.get $4
          i32.const 2
          i32.add
          local.set $4
          br $while-continue|1
         end
        end
        i32.const 0
       end
       i32.eqz
       local.set $1
       global.get $~lib/memory/__stack_pointer
       i32.const 8
       i32.add
       global.set $~lib/memory/__stack_pointer
      end
      local.get $1
      if
       global.get $~lib/memory/__stack_pointer
       local.tee $2
       local.get $0
       i32.store $0
       local.get $2
       local.get $0
       i32.store $0 offset=12
       local.get $0
       i32.const 20
       i32.sub
       i32.load $0 offset=16
       i32.const 1
       i32.shr_u
       local.set $1
       local.get $2
       i32.const 8
       i32.sub
       global.set $~lib/memory/__stack_pointer
       global.get $~lib/memory/__stack_pointer
       i32.const 7332
       i32.lt_s
       br_if $folding-inner0
       global.get $~lib/memory/__stack_pointer
       local.tee $3
       i64.const 0
       i64.store $0
       local.get $3
       local.get $0
       i32.store $0
       i32.const 1
       local.get $0
       i32.const 20
       i32.sub
       i32.load $0 offset=16
       i32.const 1
       i32.shr_u
       local.tee $3
       local.get $3
       i32.const 1
       i32.gt_u
       select
       local.tee $4
       local.get $1
       local.get $3
       local.get $1
       local.get $3
       i32.lt_s
       select
       local.tee $1
       local.get $1
       local.get $4
       i32.gt_s
       select
       i32.const 1
       i32.shl
       local.set $6
       block $__inlined_func$~lib/string/String#substring
        local.get $4
        local.get $1
        local.get $1
        local.get $4
        i32.lt_s
        select
        i32.const 1
        i32.shl
        local.tee $1
        local.get $6
        i32.sub
        local.tee $4
        i32.eqz
        if
         global.get $~lib/memory/__stack_pointer
         i32.const 8
         i32.add
         global.set $~lib/memory/__stack_pointer
         i32.const 3040
         local.set $0
         br $__inlined_func$~lib/string/String#substring
        end
        local.get $6
        i32.eqz
        local.get $1
        local.get $3
        i32.const 1
        i32.shl
        i32.eq
        i32.and
        if
         global.get $~lib/memory/__stack_pointer
         i32.const 8
         i32.add
         global.set $~lib/memory/__stack_pointer
         br $__inlined_func$~lib/string/String#substring
        end
        global.get $~lib/memory/__stack_pointer
        local.get $4
        i32.const 2
        call $~lib/rt/itcms/__new
        local.tee $1
        i32.store $0 offset=4
        local.get $1
        local.get $0
        local.get $6
        i32.add
        local.get $4
        memory.copy $0 $0
        global.get $~lib/memory/__stack_pointer
        i32.const 8
        i32.add
        global.set $~lib/memory/__stack_pointer
        local.get $1
        local.set $0
       end
       local.get $2
       local.get $0
       i32.store $0 offset=16
       global.get $~lib/memory/__stack_pointer
       local.tee $1
       local.get $0
       i32.store $0
       local.get $1
       i32.const 4
       i32.sub
       global.set $~lib/memory/__stack_pointer
       global.get $~lib/memory/__stack_pointer
       i32.const 7332
       i32.lt_s
       br_if $folding-inner0
       global.get $~lib/memory/__stack_pointer
       local.tee $1
       i32.const 0
       i32.store $0
       local.get $1
       local.get $0
       i32.store $0
       local.get $0
       call $~lib/util/string/strtol<f64>
       local.set $5
       global.get $~lib/memory/__stack_pointer
       i32.const 4
       i32.add
       global.set $~lib/memory/__stack_pointer
       global.get $~lib/memory/__stack_pointer
       local.get $5
       i32.trunc_sat_f64_u
       i32.load $0
       local.tee $0
       i32.store $0 offset=20
       global.get $~lib/memory/__stack_pointer
       i32.const 1600
       i32.store $0
       global.get $~lib/memory/__stack_pointer
       local.get $0
       i32.store $0 offset=12
       global.get $~lib/memory/__stack_pointer
       local.get $0
       call $~lib/string/String.__concat
       local.tee $0
       i32.store $0 offset=8
      else
       global.get $~lib/memory/__stack_pointer
       local.tee $0
       i32.const 1600
       i32.store $0
       local.get $0
       i32.const 7120
       i32.store $0 offset=12
       local.get $0
       i32.const 7120
       call $~lib/string/String.__concat
       local.tee $0
       i32.store $0 offset=8
      end
     end
    end
   end
   global.get $~lib/memory/__stack_pointer
   i32.const 24
   i32.add
   global.set $~lib/memory/__stack_pointer
   local.get $0
   return
  end
  i32.const 40128
  i32.const 40176
  i32.const 1
  i32.const 1
  call $~lib/builtins/abort
  unreachable
 )
 (func $export:assembly/index/index (param $0 i32) (result i32)
  global.get $~lib/memory/__stack_pointer
  i32.const 4
  i32.sub
  global.set $~lib/memory/__stack_pointer
  global.get $~lib/memory/__stack_pointer
  i32.const 7332
  i32.lt_s
  if
   i32.const 40128
   i32.const 40176
   i32.const 1
   i32.const 1
   call $~lib/builtins/abort
   unreachable
  end
  global.get $~lib/memory/__stack_pointer
  local.get $0
  i32.store $0
  local.get $0
  call $assembly/index/index
  local.set $0
  global.get $~lib/memory/__stack_pointer
  i32.const 4
  i32.add
  global.set $~lib/memory/__stack_pointer
  local.get $0
 )
 (func $byn-split-outlined-A$~lib/rt/itcms/__visit (param $0 i32)
  global.get $~lib/rt/itcms/white
  local.get $0
  i32.const 20
  i32.sub
  local.tee $0
  i32.load $0 offset=4
  i32.const 3
  i32.and
  i32.eq
  if
   local.get $0
   call $~lib/rt/itcms/Object#makeGray
   global.get $~lib/rt/itcms/visitCount
   i32.const 1
   i32.add
   global.set $~lib/rt/itcms/visitCount
  end
 )
)
