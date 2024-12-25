package main

import (
    "fmt"
    "os"
	"strconv"
)

func h(x, n int) int {
	return (x >> (n * 8)) & 0xff
}

func g(x, y, z int) int {
	res := (3*x + 5*y + 7*z) % 0x100
    return ((res << 4) | (res >> 4)) & 0xff
}

func f(x, key int) int {
	x ^= key
    out_0 := g(h(x, 0), h(x, 1), 0)
    out_1 := g(h(x, 2), h(x, 1) ^ out_0, 1)
    out_2 := g(h(x, 2) ^ out_1, h(x, 3), 0)
    out_3 := g(h(x, 3), h(x, 3), 1)

    return ((out_3 << 24) | (out_2 << 16) | (out_1 << 8) | (out_0))
}

func main() {
	mode, _ := strconv.Atoi(os.Args[1])

	if mode == 3 || mode == 2 {
		target, _ := strconv.Atoi(os.Args[2])
		n, _ := strconv.Atoi(os.Args[3])
		left1_list := []int{}
		right1_list := []int{}
		left2_list := []int{}
		right2_list := []int{}
		for i := 0; i < n; i++ {
			left1, _ := strconv.Atoi(os.Args[i * 4 + 4])
			right1, _ := strconv.Atoi(os.Args[i * 4 + 5])
			left2, _ := strconv.Atoi(os.Args[i * 4 + 6])
			right2, _ := strconv.Atoi(os.Args[i * 4 + 7])

			left1_list = append(left1_list, left1)
			right1_list = append(right1_list, right1)
			left2_list = append(left2_list, left2)
			right2_list = append(right2_list, right2)
		}

		for guessed_k := 0; guessed_k < (1<<32); guessed_k++ {
			cnt_target := 0
			for i := 0; i < n; i++ {
				left1 := left1_list[i]
				right1 := right1_list[i]
				left2 := left2_list[i]
				right2 := right2_list[i]

				fake_left1 := left1 ^ f(right1, guessed_k)
				fake_left2 := left2 ^ f(right2, guessed_k)
				if fake_left1 ^ fake_left2 == target {
					cnt_target++
				} else {
					break
				}
			}
			if cnt_target == n {
				fmt.Println(guessed_k)
				break
			}
		}
	} else if mode == 1 || mode == 0 {
		n, _ := strconv.Atoi(os.Args[2])
		output_f_list := []int{}
		right_list := []int{}
		for i := 0; i < n; i++ {
			output1_f_k1, _ := strconv.Atoi(os.Args[i * 4 + 3])
			right1, _ := strconv.Atoi(os.Args[i * 4 + 4])
			output2_f_k1, _ := strconv.Atoi(os.Args[i * 4 + 5])
			right2, _ := strconv.Atoi(os.Args[i * 4 + 6])

			output_f_list = append(output_f_list, output1_f_k1)
			output_f_list = append(output_f_list, output2_f_k1)
			right_list = append(right_list, right1)
			right_list = append(right_list, right2)
		}

		n = 2 * n
		for guessed_k := 0; guessed_k < (1<<32); guessed_k++ {
			cnt_target := 0
			for i := 0; i < n; i++ {
				if output_f_list[i] == f(right_list[i], guessed_k) {
					cnt_target++
				} else {
					break
				}
			}
			if cnt_target == n {
				fmt.Println(guessed_k)
				break
			}
		}
	}
}