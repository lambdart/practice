(ns reverse-string)

(defn reverse-string
  "Revert the given string."
  [s]
  (apply str (reduce conj () s)))

