# Decks-Duel-Game
An optimal card game strategy using AVL trees and minheaps
##########################################################
### **Game Overview**
The game involves two players, each starting with an equal number of cards. Each card has a unique number. Players take turns playing cards, with the following rules:

1. **Turn Order:** One player always starts first, and they alternate turns.
2. **Scoring:** On each turn:
   - The current player chooses one of their cards.
   - The opponent also chooses one of their cards to counter.
   - If the current player's card has a higher value than the opponent's, they score a point. Otherwise, the opponent scores a point.
3. **Optimal Play:** Both players always play optimally to maximize their own scores.

The game continues until all cards have been used, and the final scores are tallied.

---

### **Input Format**
1. **First Line:** The number of cards each player has, `N`.
2. **Next N Lines:** The card numbers for the first player (Player 1).
3. **Next N Lines:** The card numbers for the second player (Player 2).
### **Output Format**
The final scores of both players in the format: Player_1_Score Player_2_Score
### **Sample Input**
4
1 3 5 7
2 4 6 8
- N = 4: Each player has 4 cards.
- Player 1's cards: `1, 3, 5, 7`
- Player 2's cards: `2, 4, 6, 8`
### **Output**
2 2
