#!/bin/bash

# Check for the presence of an argument - the path to the executable file
if [ $# -ne 1 ]; then
    echo "Usage: $0 <path_to_executable>"
    exit 1
fi

# Path to the executable program file obtained from script arguments
EXECUTABLE="$1"

# Initialize counts
TOTAL_TESTS=0
SUCCESSFUL_TESTS=0

# Test parameters in the form of five-number tuples (a b c delta epsilon)
TEST_CASES=(
    "103.27 326.901 -9.9 7 0.00001"
    "10664.99 -1076606.65 10765 9 0.00001"
    "-103.33 333.099 -9.9 7 0.00001"
    "10010 100025 250000 7.77 0.00001"
    "3319 -46613 163317 7.77 0.00001"
    "-10010 100025 -250000 1.111 0.00001"
    "-99997.78 -221998.7679 -123210 101 0.00001"
    "-111000 0 0 101 0.00001"
    "17.6 77.44 0 0.23 0.00001"
    "-17.6 77.44 0 0.23 0.00001"
    "29.7 294.03 970.299 200 0.00001"
    "-21.3 151.23 -357.911 200 0.00001"
    "0 12345 0 200 0.00001"
    "-1.12 5 -5.6 1000 0.00001"
    "1.12 5 5.6 1000 0.00001"
    "0 0 0 1000 0.00001"
    "-0.000001 1 -0.000001 1000 0.0000001"
    "-0.000001 1 -0.000001 1000 0.0001"
    "-0.000001 1 -0.000001 1000 0.1"
    "-0.000001 1 -0.000001 1000 1"
    "0 -2 0 3 0.00000001"
    "0 2 0 3 0.0001"
    "0 -2 0 3 0.1"
    "0 -2 0 3 1"
)

# Function to test the program with given parameters
run_test() {
    # Split the parameters into separate variables
    IFS=" " read -r A B C DELTA EPSILON <<< "$1"

    echo "Testing with a=$A, b=$B, c=$C, delta=$DELTA, epsilon=$EPSILON"

    # Run the program with the specified parameters and capture the OUTPUT
    OUTPUT=$("$EXECUTABLE" "$A" "$B" "$C" "$DELTA" "$EPSILON")

    # Initialize a flag to check if all ROOTs satisfy the equation within epsilon
    ALL_ROOTS_OK=true

    # Search for lines with results in the program's OUTPUT and display them
    while IFS= read -r OUTPUT_LINE; do
        if [[ $OUTPUT_LINE == "Root:"* ]]; then
            # Extract the found ROOT from the line
            ROOT=$(echo "$OUTPUT_LINE" | cut -d' ' -f2)

            # Evaluate the equation with the ROOT within the script
            EQUATION_RESULT=$(bc -l <<< "$ROOT^3 + $A*$ROOT^2 + $B*$ROOT + $C")

            # Check if the absolute value of the equation result is less than epsilon
            if (( $(echo "$EQUATION_RESULT < $EPSILON || $EQUATION_RESULT > -$EPSILON" | bc -l) )); then
                echo "  $OUTPUT_LINE OK."
            else
                echo "  $OUTPUT_LINE NO OK."
                ALL_ROOTS_OK=false
            fi
        fi
    done <<< "$OUTPUT"

    if $ALL_ROOTS_OK ; then
        ((SUCCESSFUL_TESTS++))
    fi

    ((TOTAL_TESTS++))

    echo "---------------------------------------------------------"
}

# Run tests for all sets of parameters
for TEST_CASE in "${TEST_CASES[@]}"; do
    run_test "$TEST_CASE"
done

# Display the total number of tests and successful tests
echo "Total tests: $TOTAL_TESTS"
echo "Successful tests: $SUCCESSFUL_TESTS"