package main

import (
	"fmt"
	"regexp"
)

func main() {
	var p, t string
	fmt.Scan(&p, &t)

	p = fmt.Sprintf("^%s$", p)

	r := regexp.MustCompile(p)
	if r.MatchString(t) {
		fmt.Println("Yes")
		return
	}
	fmt.Println("No")
}
