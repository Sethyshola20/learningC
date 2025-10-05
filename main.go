package main

import (
	"fmt"
	"time"
)

func printNumbers(){
	for i := 1; i < 5; i++ {
		fmt.Println("number :",i)
		time.Sleep(time.Millisecond * 100)
	}
}
func printLetters(){
	primes := [5]int{2, 3, 5, 7, 11}
	for i := 0; i < 5; i++{
		fmt.Println("letter :",primes[i])
		time.Sleep(time.Millisecond * 100)
	}
}

func main(){
	go printNumbers()
	go printLetters()

	fmt.Println("waiting for routines")

}

