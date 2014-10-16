require 'io/console'

class QuickSort
  def self.sort(values, first = 0, last = values.length-1)
    if first < last
      r = partition(values, first, last)
      # $stdin.getch
      sort(values, first, r-1)
      sort(values, r+1, last)
    end
  end

  def self.partition(values, first, last)
    j = first
    i = first - 1
    # take last element as partition value
    x = values[last]
    puts "pivot = #{x}"
    for j in first..(last-1)
      if values[j] < x
        puts "incrementing i"
        # we need to move it into the smaller number section
        i += 1
        y = values[j]
        values[j] = values[i]
        values[i] = y
      end
      print_array(values, first, last, i, j)
    end
    # now move the pivot to the middle
    y = values[i+1]
    values[i+1] = x
    values[last] = y
    puts "final array: #{values.inspect}"
    i+1
  end

  def self.print_array(values, first, last, i, j)
    values.each_index do |index|
      if index == first
        print "["
      end
      if index == i
        print "i"
      end
      if index == j
        print "j"
      end 
      print values[index]
      print ", "
      if index == last
        print "]"
      end
    end
    print "\n"
  end
end

puts QuickSort.sort [1, 3, 10, 8, 6, 9, 4, 5, 7, 2]