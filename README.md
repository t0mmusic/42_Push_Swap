# 42_Push_Swap
A basic sorting algorithm.
# Purpose
This project takes a random string of positive or negative numbers and sorts them into order from smallest to largest. 
This must be done using two stacks, meaning only the number at the top of the stacks can be manipulated at any given time. There are a number of movement options available.
# Push
Push moves the number at the top of one stack to the top of the other. For example, push_a moves the top number of stack b into the top position of stack a. 
This means that everything from stack b moves up one position in the stack, while everything in stack a moves down one.
# Swap
Swap swaps the number at the top of a stack with the number directly beneath it. For example, if stack a contained the numbers 1, 2, 3 in that order, swap_a would 
change the order to 2, 1, 3.
# Rotate
Rotate takes the first element in the stack and moves it to the end of the stack, moving everything else in the stack up one position.
# Reverse Rotate
Reverse Rotate takes the very last element in the stack and puts it in this first postion, moving everything else in the stack down one position.
# R Rotate and R Reverse Rotate
These apply rotate or reverse rotate to both stacks in one move.
# Goal
Any time one of the above movements is applied is counted as one move. The goal of this project is to sort the numbers using as few moves as possible.
# Bonus
Bonus marks for this project are earned by making an application called 'checker' which validates whether the 'push_swap' application is functioning correctly. 
This application can be run in the command line with: <br /> ARG="number string"; ./push_swap $ARG | ./checker $ARG
# Status
Ongoing. Testing now seems to sort numbers correctly, but extra steps can be made to improve efficiency.
