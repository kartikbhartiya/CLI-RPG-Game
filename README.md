# 🔥 Turn-Based Battle Game

A simple **turn-based battle game** implemented in **C++** using Object-Oriented Programming concepts.  
Built quickly to get hands-on experience with classes, constructors, and operator overloading.

---

## 🎮 Gameplay

- Two modes:
  1. **Player vs Player** – Two humans take turns.
  2. **Player vs Bot** – Bot makes random moves (heals if health < 30).

- Each player starts with:
  - **Health:** 100
  - **Energy:** 100

- Available moves:
  1. **Fireball** → Damage = 20–26, Energy cost = 30, Energy regain = 15  
  2. **Claw Attack** → Damage = 15, Energy cost = 10, Energy regain = 20  
  3. **Frozen Breath** → Damage = 20, Energy cost = 25, Energy regain = 10  
  4. **Heal** → +30 Health, Energy cost = 20, Energy regain = 15  

---

## ⚔️ Mechanics

- **Deferred Damage System**:  
  Damage is stored in a global variable `damage` and applied to the **opponent at the start of their next turn**.  
  ```cpp
  
  ## ⚔️ Mechanics

### Spam Prevention
Fireball cannot be spammed consecutively.

### Energy System
Moves consume energy and regain a portion instantly (net cost varies).

### Game End
Game ends when either player’s health or energy drops to zero.

---

## 🧠 OOP Concepts Used

- Classes and constructors
- Operator overloading (`operator<<`) for clean status display
- Randomized attack values with `rand()`
- Encapsulation of move logic inside a `movesets` class

## Future Improvements

Making the Bot more logical making it harder to win