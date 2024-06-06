# push_swap

This project is an encounter with the concept of complexity. A sorting algorithm in the C language using stacks and with limited operations to interact with the stacks to sort the numbers.

The stacks contains a random amount of negative and positive numbers without any duplicates.

The program displays the smallest list of instructions to sort the stack X, having the smallest number at the top.

## Number of steps
$${\huge \color{orange}500 \space \color{lightblue} numbers \space ≃ \space \color{lightgreen} 4825 \space \color{lightblue} steps}$$
```
===Test===
Stacksize: 500 Cases: 100
Progress : [########################################] 100%
Status : OK Average: 4825
```
$${\huge \color{orange}100 \space \color{lightblue} numbers \space ≃ \space \color{lightgreen} 585 \space \color{lightblue} steps}$$

```
===Test===
Stacksize: 100 Cases: 100
Progress : [########################################] 100%
Status : OK Average: 585
```

### A ⇌ B
![push_swap.gif](push_swap.gif)

## Flow Chart
### Main flow
```mermaid
%%{ init: { 'flowchart': { 'curve': 'monotoneY' } } }%%
flowchart TD
    Start((Constructor)) --> input{Type of input}
    input -- One string of args --> oneArgs[Convert into vector of arguments]
    input -- Vector of args --> Analyzer
    input -- No arguments --> ExitSuccess(EXIT_SUCCESS)
    oneArgs --> Analyzer
    subgraph Analyzer
    Lexer{{Lexer : Only numerical arguments}} --> Parser{{Parser : Negative sign position}}
    Parser --> Semantic{{Semantic Analyzer : No duplicates, Int size limit}}
    end
    Analyzer -- Error --> Perror[Print Error]
    Perror --> ExitError(EXIT_FAILURE)
    Analyzer -- Success --> Stacks

    subgraph Stacks[Create stacks as double linked lists]
    StackA[(Create Stack A)] --> lsa[Load Stack A]
    lsa --> StackB[(Create Stack B)]
    StackB --> ListInstruct[(Create Stack Op)]
    end
    Stacks --> Sort{{Sorting algorithm : Loads Instructions list}}
    Sort --> Reduce[Reduce Instructions list]
    Reduce --> printInstruct[Print instructions]
    printInstruct -->  ExitSuccess
    ExitSuccess --> Destructor((Destructor))
    ExitError --> Destructor

```
### Sorting algorithm
```mermaid
%%{ init: { 'flowchart': { 'curve': 'monotoneY' } } }%%
flowchart LR
    subgraph Sorting[Sorting Algorithm]
        direction LR
        subgraph FirstStep[Stack A to B]
                direction TB
                subgraph Define
                    direction LR
                    sorted{{Sorted := Array with the numbers sorted}}
                    middle[/Middle := Middle of SORTED array/]
                    offset[/Offset := Size of partitions/]
                    inset[/Inset := Limit from Middle - offset/]
                    outset[/Outset := Limit from Middle + offset - 1/]
                end
                Define --> a2b{Stack A is empty}
                a2b -- No --> topInRange{"A's top number is\ninside [inset, outset]"}
                topInRange -- Yes --> pb1[pb]
                pb1 --> rmNumber["DEL num from Sorted Array"]
                rmNumber --> inInset{"The number was\n[inset, middle]"}
                inInset -- Yes --> rb1[rb]
                topInRange -- No --> ra1[ra]
                rb1 --> emptyInset{"[inset, middle] is empty"}
                emptyInset -- Yes --> addInset[inset -= offset]
                inInset -- No --> emptyOutset{"[middle, outset] is empty"}
                emptyOutset -- Yes --> addOutset[outset += offset]
                ra1 --> eol[End of loop]
                emptyOutset -- No --> eol
                emptyInset -- No --> eol
                addOutset --> eol
                addInset --> eol
                eol --> a2b
        end
        subgraph SecondStep[Stack B to A]
                direction TB
                subgraph Define2[Define]
                    direction LR
                    tail[/A.tail := Active partition in tail of A/]
                    btail[/B.tail := Active partition in tail of B/]
                    bhead[/B.head := Active partition in head of B/]
                end
                Define2 --> b2a{Stack B and A.tail are empty\n}
                b2a --No--> search{"Search for max(B.head + B.tail + A.tail) number"}
                search --"First element of B"--> pa{{pa}}
                search --"Last element of A"--> rra{{rra}}
                search --"A.tail is empty\nor\nFirst element of B > Last element of A"-->para{{"pa\nra"}}
                search --"else"--> else{Where is the\nmax number}
                else --"B.head"--> rb{{rb}}
                else --"B.tail"--> rrb{{rrb}}
                rb --> eol2[End of loop]
                rrb --> eol2
                pa --> eol2
                rra --> eol2
                para --> eol2
                eol2 --> b2a

        end
        FirstStep --> SecondStep
    end
```
## Operations

let X be the name of the stack (a and b):
ss, rr and rrr: are just two operations in one (sa && sb, ra && rb, ...)
### Swap
swap the first 2 elements at the top of stack X.
- `sX`
- `ss`
### Push
Pass top element from Y and put it on top of X.
- `pX`
### Rotate
Shift up all elements of stack X by 1.
- `rX`
- `rr`
### Reverse rotate
Shift down all elements of stack X by 1.
- `rrX`
- `rrr`

## Build
```bash
make
```

## Verbose output
### To see a verbose output use:
```bash
export PS_VERBOSE=1
```
### To unset this feature, use:
```bash
unset PS_VERBOSE
```

## Usage
```bash
# Multiple arguments
./push_swap [num1] [num2] ... [numN]
# One argument
./push_swap "[num1] [num2] ... [numN]"
```
Which translates into:
| stack X|
|----|
|num1|
|num2|
|...|
|numN|

| stack Y|
|----|
| empty|
| empty|
| empty|
| empty|
## Example
```bash
./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
./push_swap one two 3
Error
```

```bash
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker $ARG
```

###### Recomended tester
*https://github.com/zaperfish/push_swap_tester.git*
###### Recomended visualizer
*https://github.com/o-reo/push_swap_visualizer.git*
