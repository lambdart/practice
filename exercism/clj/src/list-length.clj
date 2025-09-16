;; define out namespace
(ns hackerrank.listLength)

(defn solution [lst]
  (apply + (map (fn [_] 1) lst)))

