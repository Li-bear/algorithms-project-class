sortData = read.delim2("C:\\Users\\ASUS\\Documents\\University\\winter 2223\\project_algorithms\\algorithms-project-class\\results.txt", header=TRUE, sep = "\t")
print(sortData)

plot(x=sortData$Len,y=sortData$Insertion, type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="blue", main="Time comparison four sorting algorithms")
lines(x=sortData$Len, y=sortData$Heap.sort, type="l", col="red")


plot(x=sortData$Len,y=sortData$Heap.sort, type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="red", main="Time comparison without Insertion algorithm")
lines(x=sortData$Len, y=sortData$Merge.sort, type="l", col="green")
lines(x=sortData$Len, y=sortData$Quick.sort, type="l", col="purple")
legend(1000, 2000000, legend=c("Heap sort", "Merge sort", "Quick sort"),
       col=c("red", "green", "purple"), lty=1, cex=0.8,)


plot(x=sortData$Len[1:10],y=sortData$Heap.sort[1:10], type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="red", main="Time comparison without Insertion algorithm")
lines(x=sortData$Len[1:10], y=sortData$Insertion[1:10], type="l", col="blue")
lines(x=sortData$Len[1:10], y=sortData$Merge.sort[1:10], type="l", col="green")
lines(x=sortData$Len[1:10], y=sortData$Quick.sort[1:10], type="l", col="purple")

# Comparison all random data until length 10000
randomData = read.delim2("C:\\Users\\ASUS\\Documents\\University\\winter 2223\\project_algorithms\\algorithms-project-class\\results_random.txt", header=TRUE, sep = "\t")
plot(x=randomData$Len,y=randomData$Heap.sort, type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="red", main="Random values",lty=2)
lines(x=randomData$Len, y=randomData$Merge.sort, type="l", col="green", lty=2)
lines(x=randomData$Len, y=randomData$Quick.sort, type="l", col="purple", lty=2)
legend(1000, 2000000, legend=c("Heap sort", "Merge sort", "Quick sort"), title="Algorithms",
       col=c("red", "green", "purple"), lty=2, cex=0.8,)

# Comparison data under length 1200 - four algo
m_i = 15
plot(x=randomData$Len[1:m_i],y=randomData$Heap.sort[1:m_i], type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="red", main="Random data time comparison", lty=2)
lines(x=randomData$Len[1:m_i], y=randomData$Insertion[1:m_i], type="l", col="blue", lty=2)
lines(x=randomData$Len[1:m_i], y=randomData$Merge.sort[1:m_i], type="l", col="green", lty=2)
lines(x=randomData$Len[1:m_i], y=randomData$Quick.sort[1:m_i], type="l", col="purple", lty=2)

lines(x=sortData$Len[1:m_i], y=sortData$Heap.sort[1:m_i], type="l", col="red")
lines(x=sortData$Len[1:m_i], y=sortData$Insertion[1:m_i], type="l", col="blue")
lines(x=sortData$Len[1:m_i], y=sortData$Merge.sort[1:m_i], type="l", col="green")
lines(x=sortData$Len[1:m_i], y=sortData$Quick.sort[1:m_i], type="l", col="purple")

legend(800, 63000, legend=c("Heap sort", "Merge sort", "Quick sort", "Insertion"), title="Shuffle data",
       col=c("red", "green", "purple", "blue"), lty=1, cex=0.8)

legend(1200, 63000, legend=c("Heap sort", "Merge sort", "Quick sort", "Insertion"), title="Random data",
       col=c("red", "green", "purple", "blue"), lty=2, cex=0.8)

# Average line
plot(x=randomData$Len,y=(randomData$Merge.sort + sortData$Merge.sort)/2, type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="green", main="Average", lty=3)
lines(x=sortData$Len, y=(randomData$Quick.sort + sortData$Quick.sort)/2, type="l", col="purple")

# average line under index
plot(x=randomData$Len[1:m_i],y=(randomData$Merge.sort[1:m_i] + sortData$Merge.sort[1:m_i])/2, type="l", xlab="Length vector", ylab = "Time to sort (ns)", col="green", main="Average")
lines(x=sortData$Len[1:m_i], y=(randomData$Quick.sort[1:m_i]+ sortData$Quick.sort[1:m_i])/2, type="l", col="purple")
