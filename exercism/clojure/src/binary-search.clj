(ns binary-search)

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

