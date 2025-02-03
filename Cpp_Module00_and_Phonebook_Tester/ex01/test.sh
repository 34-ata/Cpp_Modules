expected="|         0|         0|         0|         0|
|         1|   1|   1|   1|
|         2|   2|   2|   2|
|         3|   3|   3|   3|
|         4|   4|   4|   4|
|         5|   5|   5|   5|
|         6|   6|   6|   6|
|         7|   7|   7|   7|
"

{
    for i in {0..7}
    do
        echo "ADD"
        echo "default"
        echo "default"
        echo "default"
        echo "default"
        echo "default"
    done

    for i in {0..7}
    do
        echo "ADD"
        echo "$i"
        echo "$i"
        echo "$i"
        echo "$i"
        echo "$i"
    done

    echo "SEARCH"
} | ./phonebook > test.txt

program_output=$(awk '/         0/ {found=1} found && !/Enter the index/ {print} /Enter the index/ {found=0}' test.txt)

program_output=$(echo "$program_output" | tr -s '[:space:]')
expected=$(echo "$expected" | tr -s '[:space:]')

echo -e "\n--- Expected Output ---"
echo "$expected"

echo -e "\n--- Program Output ---"
echo "$program_output"

if [ "$program_output" == "$expected" ]; then
    echo -e "\nResult: success"
else
    echo -e "\nResult: error"
fi

rm test.txt
