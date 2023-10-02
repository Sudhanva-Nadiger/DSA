func winnerOfGame(colors string) bool {
    n := len(colors)
    if n <= 2 { return false }
        
    alice, bob := 0, 0

    for i := 1; i+1 < n; i++ {
        if (colors[i-1] == colors[i]) && (colors[i] == colors[i+1]) {
            if colors[i] == 'A' {
                alice++;
            } else {
                bob++;
            }
        }
    }

    return alice > bob
}