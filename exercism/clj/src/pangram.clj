(ns pangram)

(defn pangram? [s]
  (empty?
   (apply disj
          (set (take 26 (iterate (comp char inc int) \a)))
          (seq (clojure.string/lower-case s)))))
