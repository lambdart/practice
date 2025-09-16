;; define out namespace
(ns hackerrank.filterPos)

;; c -> collection (list or vector)
(defn solution [c]
  (remove false?
          (map-indexed (fn [i v] (and (odd? i) v)) c)))
