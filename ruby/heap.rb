class Heap
  def initialize(initial)
    @data = initial
    # puts "starting is #{@data}"
    (initial.length/2).downto(0).each do |index|
      max_heapify index, @data.length
    end
  end

  def sort(length = @data.length)
    puts "sort"
    # swap max and end element, and re-max-heapify
    max = @data[0]
    puts "swap 0 and #{length-1}"
    @data[0] = @data[length-1]
    @data[length-1] = max
    max_heapify(0, length-1)
    puts "#{@data}"
    if 0 < length-1
      sort(length-1)
    end
    @data
  end

  private

  def max_heapify(index, length)
    # puts "max heapifying #{index}"
    max_index = index
    if left(index) < length && @data[left(index)] > @data[max_index]
      max_index = left(index)
    end
    if right(index) < length && @data[right(index)] > @data[max_index]
      max_index = right(index)
    end
    # puts "biggest at #{max_index}"
    if max_index != index
      max = @data[max_index]
      @data[max_index] = @data[index]
      @data[index] = max
      max_heapify(max_index, length)
    end
    # puts "now array is #{@data}"
  end

  def left(index)
    return 2 * index + 1
  end

  def right(index)
    return 2 * index + 2
  end
end

h = Heap.new([1, 3, 10, 8, 6, 9, 4, 5, 7, 2])
puts h.sort