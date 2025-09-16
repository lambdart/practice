(ns squeaky-clean
  (:require [clojure.string :as str]))

(defn clean
  [s]
  (apply str (map (fn [c]
                    (if (= c \space) \_ c))
                  (seq s))))

