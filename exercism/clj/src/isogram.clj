(ns isogram)

(defn isogram?
  "Returns true if the given string is an isogram; otherwise, returns false"
  [s]
  (let [fs (-> s
               clojure.string/lower-case
               frequencies
               (#(apply dissoc % '(\space \-))))]
    (loop [ks (keys fs)]
      (cond (empty? ks) true
            (> (get fs (first ks)) 1) false
            :else
            (recur (rest ks))))))
