count=10
operations=0
total=0
for i in $(seq $count); do
    ./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l >> result
done

echo "10.000 combinations // 500 Numbers // 24 groups" >> report
echo "===" >> report
echo "MAX" >> report
cat result | sort -n | tail -1 >> report
echo "MIN" >> report
cat result | sort -n | head -1 >> report
echo "MED" >> report
awk '{total += $1; operations++} END {print total/operations}' result >> report
