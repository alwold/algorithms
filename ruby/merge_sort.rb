class MergeSort
  def self.sort(values)
    if values.length == 1
      values
    else
      middle = values.length / 2 - 1
      values1 = sort(values[0..middle])
      values2 = sort(values[middle+1..-1])
      merge(values1, values2)
    end
  end

  def self.merge(values1, values2)
    values = []
    i = 0
    j = 0
    loop do
      if values1[i] < values2[j]
        values << values1[i]
        i += 1
      else
        values << values2[j]
        j += 1
      end
      break if i >= values1.length || j >= values2.length
    end
    while i < values1.length do
      values << values1[i]
      i += 1
    end
    while j < values2.length do
      values << values2[j]
      j += 1
    end
    values
  end
end

puts MergeSort.sort [1, 3, 10, 8, 6, 9, 4, 5, 7, 2]