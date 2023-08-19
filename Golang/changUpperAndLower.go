package main

import "fmt"

func main() {
    var s1 string
    fmt.Scan(&s1)
    
    for i := 0; i < len(s1); i++ {
        if s1[i] >= 'a' && s1[i] <= 'z'{
            fmt.Printf("%c", s1[i] - 32)
        }else{
            fmt.Printf("%c", s1[i] + 32)
        }
    }
}
