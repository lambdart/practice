(ns lab)

(defn read-value []
  (Integer/parseInt (read-line)))

(defn bit-shift-right-or-left [x s]
  (let [temp (Math/abs s)]
    (if (> s 0)
      (bit-shift-left x temp)
      (bit-shift-right x temp))))

(defn sierpinsky [s y x]
  (let [m (- (bit-shift-right-or-left 1 s) 1)]
    (and (> m (+ (bit-and m (- x y)) (bit-and m (* y 2))))
         (= 0 (bit-shift-right-or-left (bit-and (- x y)
                                                (* y 2))
                                       (- s))))))
(defn solution [n]
  (doseq [y (range 31 -1 -1)]
    (doseq [x (range 63)]
      (print (if (sierpinsky (- 6 n) y x) "1" "_")))
    (newline)))

(solution (read-value))
