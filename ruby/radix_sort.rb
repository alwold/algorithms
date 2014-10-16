class RadixSort
  def self.sort(values)
    max_digits = 0
    values.each do |value|
      if Math.log10(value) > max_digits
        max_digits = Math.log10(value)
      end
    end
    max_digits = max_digits.ceil
    (1..max_digits).each do |digit|
      puts "digit = #{digit}"
      buckets = Array.new
      10.times {
        buckets << Array.new
      }
      values.each do |value|
        n = value / 10**(digit-1)
        current_digit = n % 10
        puts "current digit #{current_digit}"
        buckets[current_digit] << value
      end
      puts "buckets: #{buckets.inspect}"
      values = Array.new
      buckets.each do |bucket|
        bucket.each do |value|
          values << value
        end
      end
      puts "values: #{values.inspect}"
    end
    values
  end
end

puts "final: " << RadixSort.sort([170, 45, 75, 90, 802, 2, 24, 66]).inspect