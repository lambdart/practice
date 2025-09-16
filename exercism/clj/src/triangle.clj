(ns triangle)

(defn triangle?
  [a b c]
  (not (or (zero? a)
           (zero? b)
           (zero? c)
           (< (+ a b) c)
           (< (+ b c) a)
           (< (+ a c) b))))

(defn equilateral?
  "Returns true if the triangle with sides a, b,
  and c is equilateral; otherwise, returns false."
  [a b c]
  (and (triangle? a b c)
       (= a b c)))

(defn isosceles?
  "Returns true if the triangle with sides a, b,
  and c is isosceles; otherwise, returns false."
  [a b c]
  (and (triangle? a b c)
       (or (= a b)
           (= b a)
           (= b c)
           (= a c))))

(defn scalene?
  "Returns true if the triangle with sides a, b,
  and c is scalene; otherwise, returns false."
  [a b c]
  (and (triangle? a b c)
       (not (or (= a b)
                (= a c)
                (= b c)))))
