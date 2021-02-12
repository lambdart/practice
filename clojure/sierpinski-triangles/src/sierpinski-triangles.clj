(ns lab)

(defn read-value []
  (Integer/parseInt (read-line)))

(defn sierpinski [s y x]
  (let [m (- (bit-shift-left 1 s) 1)]
    (and (> m (+ (bit-and m (- x y)) (bit-and m (* y 2))))
         (= 0 (bit-shift-right (bit-and (- x y)
                                        (* y 2))
                               s)))))

(defn solution [n]
  (doseq [y (range 31 -1 -1)]
    (doseq [x (range 63)]
      (print (if (sierpinski (- 6 n) y x) "1" "_")))
    (newline)))

(solution (read-value))
