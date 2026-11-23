

class ProductOfNumbers {
    private ArrayList<Integer> prefixProduct;

    public ProductOfNumbers() {
        prefixProduct = new ArrayList<>();
        prefixProduct.add(1); // Base case: product of zero elements is 1
    }

    public void add(int num) {
        if (num == 0) {
            // Reset on zero because everything before becomes invalid
            prefixProduct.clear();
            prefixProduct.add(1);
        } else {
            int lastProduct = prefixProduct.get(prefixProduct.size() - 1);
            prefixProduct.add(lastProduct * num);
        }
    }

    public int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) return 0; // If k is larger than the valid range, return 0
        return prefixProduct.get(n - 1) / prefixProduct.get(n - 1 - k);
    }
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */