(ns solution.reverse-string)

(defn reverse-string [s]
  (apply str (reduce conj () s)))

(defn reverse-string [s]
  (apply str (into () (seq s))))

(defn sorted-random-numbers [n l]
  (sort (take n (repeatedly #(rand-int l)))))

