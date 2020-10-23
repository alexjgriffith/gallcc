(tset package :cpath (.. package.cpath ";../build/?.so"))

(local sample (require "sample"))

(local pp (fn [x] (print ((require :extralib.fennelview) x))))

(local input-obj {:text "name" :height 1 :strength 2})

(local input-name {:text "name"})

(local tests {})

(fn tests.obj [{: text : height : strength} _name]
  (let [obj (sample.new_obj text height strength)
        obj-data (sample.get_obj_data obj)]
    (pp input-obj)
    (pp obj)
    (pp obj-data)))

(fn tests.name [_obj {: text}]
  (let [text (sample.new_name text)
        text-data (sample.get_name_data text)]
    (pp input-name)
    (pp text)
    (pp text-data)))

(each [key test (pairs tests)]
  (test input-obj input-name))
