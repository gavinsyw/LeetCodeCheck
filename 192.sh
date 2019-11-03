# 4ms, 3.3MB

# Read from the file words.txt and output the word frequency list to stdout.

cat words.txt | tr -cs "[a-z]" "\n" | sort | uniq -c | sort -k1nr | awk '{print $2 " " $1}'