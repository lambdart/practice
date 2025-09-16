(ns binary-search)

(defn binary-search [x col]
  (let [arr (vec col)
        n (dec (count arr))]
    (loop [[i j] [0 n]]
      (cond
        (or (< j 0) (> j n)
            (< i 0) (> i n)) -1
        :else
        (let [m (int (/ (+ i j) 2))
              y (get arr m)]
          (cond
            (= x y) m
            :else
            (recur (if (> x y) [(inc m) j] [i (dec m)]))))))))

(defn search-for [x arr]
  (let [arr (vec arr)]
    (loop [[a b] [0 (count arr)]]
      (let [i (int (/ (+ a b) 2))
            y (get arr i)]
        (cond
          (nil? y) (throw (Exception. "not found"))
          (= x y) i
          :else
          (recur (if (> x y) [(inc i) b] [a (dec i)])))))))

(defn middle [arr]
  (let [mid (get arr (int (/ (count arr) 2)))]
    (search-for mid arr)))

(defn sorted-random-numbers [n l]
  (sort (take n (repeatedly #(rand-int l)))))

;; (sorted-random-numbers 10000 2000)

