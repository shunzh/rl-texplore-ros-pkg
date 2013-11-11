; Auto-generated. Do not edit!


(cl:in-package rl_msgs-msg)


;//! \htmlinclude RLStateReward.msg.html

(cl:defclass <RLStateReward> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (reward
    :reader reward
    :initarg :reward
    :type cl:float
    :initform 0.0)
   (terminal
    :reader terminal
    :initarg :terminal
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RLStateReward (<RLStateReward>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RLStateReward>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RLStateReward)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rl_msgs-msg:<RLStateReward> is deprecated: use rl_msgs-msg:RLStateReward instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <RLStateReward>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:state-val is deprecated.  Use rl_msgs-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'reward-val :lambda-list '(m))
(cl:defmethod reward-val ((m <RLStateReward>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:reward-val is deprecated.  Use rl_msgs-msg:reward instead.")
  (reward m))

(cl:ensure-generic-function 'terminal-val :lambda-list '(m))
(cl:defmethod terminal-val ((m <RLStateReward>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:terminal-val is deprecated.  Use rl_msgs-msg:terminal instead.")
  (terminal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RLStateReward>) ostream)
  "Serializes a message object of type '<RLStateReward>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'state))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'state))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'reward))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'terminal) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RLStateReward>) istream)
  "Deserializes a message object of type '<RLStateReward>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'state) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'state)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'reward) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'terminal) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RLStateReward>)))
  "Returns string type for a message object of type '<RLStateReward>"
  "rl_msgs/RLStateReward")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RLStateReward)))
  "Returns string type for a message object of type 'RLStateReward"
  "rl_msgs/RLStateReward")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RLStateReward>)))
  "Returns md5sum for a message object of type '<RLStateReward>"
  "d7e0cc8b9cf2889f09d7f096a11a2873")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RLStateReward)))
  "Returns md5sum for a message object of type 'RLStateReward"
  "d7e0cc8b9cf2889f09d7f096a11a2873")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RLStateReward>)))
  "Returns full string definition for message of type '<RLStateReward>"
  (cl:format cl:nil "# Message for returning the current sensation vector ~%# (i.e. state or observation or sensor readings) and a~%# reward from an  environment~%~%float32[] state~%float32 reward~%bool terminal~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RLStateReward)))
  "Returns full string definition for message of type 'RLStateReward"
  (cl:format cl:nil "# Message for returning the current sensation vector ~%# (i.e. state or observation or sensor readings) and a~%# reward from an  environment~%~%float32[] state~%float32 reward~%bool terminal~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RLStateReward>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'state) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RLStateReward>))
  "Converts a ROS message object to a list"
  (cl:list 'RLStateReward
    (cl:cons ':state (state msg))
    (cl:cons ':reward (reward msg))
    (cl:cons ':terminal (terminal msg))
))
