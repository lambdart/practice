;; define out namespace
(ns hackerrank.updateList)

(defn solution [lst]
  (map (fn [v] (Math/abs v)) lst))

