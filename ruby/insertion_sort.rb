class InsertionSort
  def self.sort(values)
    puts values.inspect
    1.upto(values.length-1) do |j|
      x = values[j]
      i = j - 1
      while i >= 0 && values[i] > x
        # move i forward
        values[i+1] = values[i]
        i -= 1
      end
      # here, i should point at the position before where the value goes
      values[i+1] = x
      puts values.inspect
    end
    values
  end
end

puts InsertionSort.sort([1, 3, 10, 8, 6, 9, 4, 5, 7, 2]).inspect