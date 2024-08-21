import java.util.ArrayList;
import java.util.LinkedList;

class Hash {

    int BUCKET;
    ArrayList<LinkedList<Integer>> table;
    Hash(int b)
    {
        BUCKET = b;
        table = new ArrayList<LinkedList<Integer>>();
        for (int i = 0; i < b; i++)
            table.add(new LinkedList<Integer>());
    }
    void insert(Integer k)
    {
        int i = k % BUCKET;
        table.get(i).add(k);
    }
    boolean search(Integer k)
    {
        int i = k % BUCKET;
        return table.get(i).contains(k);
    }
    void deleteItem(Integer k)
    {
        int i = k % BUCKET;
        table.get(i).remove(k);
    }
}

class PrepInsta
{
    public static void main(String[] args)
    {
        Hash h = new Hash(7);
        h.insert(3);
        h.insert(8);
        h.insert(5);
        h.insert(1);
        h.insert(10);
        h.insert(6);
        System.out.println(h.search(10));
        h.deleteItem(10);
        System.out.println(h.search(1));
    }
}