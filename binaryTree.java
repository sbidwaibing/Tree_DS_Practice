class Node
{
    int data;
    Node left, right;

    public Node(int value)
    {
        data = value;
        left = right = null;
    }
}

public class binaryTree {   
    public static void main(String args[])
    {
        //create a root node
        Node root = new Node(1);
        
        //create a child node
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(5);

        System.out.println("Root Node Data: "+root.data);
        System.out.println("Left Child Data: "+root.left.data);
        System.out.println("Right Child Data: "+root.right.data);
        System.out.println("Left-Right Child Data: "+root.left.right.data);
    }
}

