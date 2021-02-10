(ns reverse-string)

(defn reverse-string [s]
  (apply (reduce conj () s)))

