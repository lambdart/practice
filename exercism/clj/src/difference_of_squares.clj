(ns difference-of-squares)

(defn square [x]
  (* x x))

(defn abs [x]
  (* x (if (> x 0) 1 -1)))

(defn square-of-sum
  "Returns the square of the sum of the numbers up to the given number"
  [n]
  (square
   (reduce (fn [x y]
             (+ x y))
           1
           (take (- n 1) (iterate inc 2)))))

(defn sum-of-squares
  "Returns the sum of the squares of the numbers up to the given number"
  [n]
  (apply + (map square (take n (iterate inc 1)))))

(defn difference
  "Returns the difference between the square of the sum of numbers up to a given number and the sum of the squares of those numbers"
  [n]
  (abs (- (sum-of-squares n)
          (square-of-sum n))))
