(ns solutions.fibonacci)

(defn fib
  "Return `n` elements of Fibonacci sequence."
  [n]
  (->> [1 1]
       (iterate (fn [[a b]] [b (+ a b)]))
       (map first)
       (take n)))

(defn nthfib
  "Return the `n`th Fibonacci element."
  [n]
  (nth (fib n) (dec n)))
