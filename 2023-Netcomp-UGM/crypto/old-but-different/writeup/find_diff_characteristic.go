package main

import (
	"fmt"
)

func g(x, y, z int) int {
	res := (3*x + 5*y + 7*z) % 0x100
	return ((res << 4) | (res >> 4)) & 0xff
}

func main() {
	cnt := 0
	for diff1 := 0; diff1 < 256; diff1++ {
		for diff2 := 0; diff2 < 256; diff2++ {
			st := map[int]int{}
			for a1 := 0; a1 < 256; a1++ {
				for b1 := 0; b1 < 256; b1++ {
					for x := 0; x < 2; x++ {
						cnt += 1
						if cnt % 100000000 == 0 {
							fmt.Println("cnt:", cnt)
						}
						a2 := a1 ^ diff1
                    	b2 := b1 ^ diff2
                    	g1 := g(a1, b1, x)
                    	g2 := g(a2, b2, x)
                    	st[g1 ^ g2] += 1
					}
				}
			}
			if len(st) < 3 {
				fmt.Println("========================================")
				fmt.Printf("diff1: %d, diff2: %d\n", diff1, diff2)
				for k, v := range st {
					fmt.Printf("g: %d, count: %d\n", k, v)
				}
				fmt.Println("========================================")
			}
		}
	}
}