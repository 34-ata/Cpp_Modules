RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

declare -a test_cases=(
    "42"
    "0"
    "-42"
    "42.0"
    "-42.42"
    "3.14159"
    "1e3"
    "2.5e-4"
    "a"
    "nan"
    "inff"
    "-inff"
    "not_a_number"
)

compare_output()
{
    expected="$1"
    actual="$2"

    echo -e "${BLUE}Expected output:${RESET}"
    echo "$expected"
    echo -e "${BLUE}Actual output:${RESET}"
    echo "$actual"

    if [ "$expected" == "$actual" ]; then
        echo -e "${GREEN}PASSED${RESET}"
    else
        echo -e "${RED}FAILED${RESET}"
        echo -e "${YELLOW}Expected:${RESET} $expected"
        echo -e "${YELLOW}Actual:${RESET} $actual"
    fi
}

for test_case in "${test_cases[@]}"; do
    echo -e "${BLUE}Running ./convert with argument: $test_case${RESET}"
    
    actual_output=$(./convert "$test_case")

    case "$test_case" in
        "42")
            expected_output="char: '*'
int: 42
float: 42.0f
double: 42.0"
            ;;
        "0")
            expected_output="char: Non displayable
int: 0
float: 0.0f
double: 0.0"
            ;;
        "-42")
            expected_output="char: Non displayable
int: -42
float: -42.0f
double: -42.0"
            ;;
        "42.0")
            expected_output="char: '*'
int: 42
float: 42.0f
double: 42.0"
            ;;
        "-42.42")
            expected_output="char: Non displayable
int: -42
float: -42.42f
double: -42.42"
            ;;
        "3.14159")
            expected_output="char: Non displayable
int: 3
float: 3.14159f
double: 3.14159"
            ;;
        "1e3")
            expected_output="char: Non displayable
int: 1000
float: 1000.0f
double: 1000.0"
            ;;
        "2.5e-4")
            expected_output="char: Non displayable
int: 0
float: 0.00025f
double: 0.00025"
            ;;
        "a")
            expected_output="char: 'a'
int: 97
float: 97.0f
double: 97.0"
            ;;
        "nan")
            expected_output="char: impossible
int: impossible
float: nanf
double: nan"
            ;;
        "inff")
            expected_output="char: impossible
int: impossible
float: inff
double: inf"
            ;;
        "-inff")
            expected_output="char: impossible
int: impossible
float: -inff
double: -inf"
            ;;
        "not_a_number")
            expected_output="Error: Invalid input"
            ;;
        *)
            expected_output="Error: Invalid input"
            ;;
    esac

    compare_output "$expected_output" "$actual_output"

    echo -e "${BLUE}-----------------------------${RESET}"
done
