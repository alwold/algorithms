class BstNode
  attr_accessor :value
  attr_accessor :parent
  attr_accessor :left
  attr_accessor :right

  def initialize(value, parent)
    @value = value
    @parent = parent
    @left = nil
    @right = nil
  end

  def height
    if @left && @right
      [@left.height, @right.height].max+1
    elsif @left
      @left.height+1
    elsif @right
      @right.height+1
    else
      1
    end
  end
end

class Bst
  def initialize(values)
    values.each do |value|
      insert value
    end
  end

  def insert(value)
    if @root == nil
      @root = BstNode.new(value, nil)
    else
      current = @root
      loop do
        if value < current.value
          if current.left
            current = current.left
          else
            current.left = BstNode.new(value, current)
            break
          end
        else
          if current.right
            current = current.right
          else
            current.right = BstNode.new(value, current)
            break
          end
        end
      end
    end
  end

  def to_s
    node_to_s(@root)
  end

  def height
    @root.height
  end

  def node_to_s(node)
    buf = ''
    if node.left
      buf << node_to_s(node.left)
    end
    buf << "#{node.value} "
    if node.right
      buf << node_to_s(node.right)
    end
    buf
  end
end

bst = Bst.new([1, 2, 3, 4, 5, 6, 7, 8, 9, 10].shuffle)
puts bst
puts "height = #{bst.height}"