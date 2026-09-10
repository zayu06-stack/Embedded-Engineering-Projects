

\### `pin\_map.md`



```markdown

\# Pin Map



\## Arduino Uno Pin Assignments



| Component | Component Pin | Arduino Pin |

|---|---|---|

| 16x2 LCD | RS | D7 |

| 16x2 LCD | E | D6 |

| 16x2 LCD | D4 | D5 |

| 16x2 LCD | D5 | D4 |

| 16x2 LCD | D6 | D3 |

| 16x2 LCD | D7 | D2 |

| Pushbutton | Signal | D8 |

| Passive Buzzer | Signal | D9 |



\## LCD Power Connections



| LCD Pin | Label | Connection |

|---|---|---|

| 1 | VSS | GND |

| 2 | VDD | 5V |

| 3 | VO | Contrast connection |

| 4 | RS | Arduino D7 |

| 5 | RW | GND |

| 6 | E | Arduino D6 |

| 7 | D0 | Not connected |

| 8 | D1 | Not connected |

| 9 | D2 | Not connected |

| 10 | D3 | Not connected |

| 11 | D4 | Arduino D5 |

| 12 | D5 | Arduino D4 |

| 13 | D6 | Arduino D3 |

| 14 | D7 | Arduino D2 |

| 15 | A / LED+ | 5V |

| 16 | K / LED- | GND |



\## LiquidCrystal Configuration



The LCD is initialized with:



```cpp

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

