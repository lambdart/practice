;; define out namespace
(ns hackerrank.filterArray)

;; x -> upper limit
;; c -> collection (list or vector)
(defn solution [x c]
  (filter (fn [v] (and (< v x) v)w) c)

  (map-indexed (fn [i v] (and (even? i) v)) '(2 5 3 4 6 7 9 8))



