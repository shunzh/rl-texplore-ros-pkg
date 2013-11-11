; Auto-generated. Do not edit!


(cl:in-package rl_msgs-msg)


;//! \htmlinclude RLEnvSeedExperience.msg.html

(cl:defclass <RLEnvSeedExperience> (roslisp-msg-protocol:ros-message)
  ((from_state
    :reader from_state
    :initarg :from_state
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (action
    :reader action
    :initarg :action
    :type cl:integer
    :initform 0)
   (to_state
    :reader to_state
    :initarg :to_state
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

(cl:defclass RLEnvSeedExperience (<RLEnvSeedExperience>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RLEnvSeedExperience>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RLEnvSeedExperience)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rl_msgs-msg:<RLEnvSeedExperience> is deprecated: use rl_msgs-msg:RLEnvSeedExperience instead.")))

(cl:ensure-generic-function 'from_state-val :lambda-list '(m))
(cl:defmethod from_state-val ((m <RLEnvSeedExperience>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:from_state-val is deprecated.  Use rl_msgs-msg:from_state instead.")
  (from_state m))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <RLEnvSeedExperience>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:action-val is deprecated.  Use rl_msgs-msg:action instead.")
  (action m))

(cl:ensure-generic-function 'to_state-val :lambda-list '(m))
(cl:defmethod to_state-val ((m <RLEnvSeedExperience>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:to_state-val is deprecated.  Use rl_msgs-msg:to_state instead.")
  (to_state m))

(cl:ensure-generic-function 'reward-val :lambda-list '(m))
(cl:defmethod reward-val ((m <RLEnvSeedExperience>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:reward-val is deprecated.  Use rl_msgs-msg:reward instead.")
  (reward m))

(cl:ensure-generic-function 'terminal-val :lambda-list '(m))
(cl:defmethod terminal-val ((m <RLEnvSeedExperience>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:terminal-val is deprecated.  Use rl_msgs-msg:terminal instead.")
  (terminal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RLEnvSeedExperience>) ostream)
  "Serializes a message object of type '<RLEnvSeedExperience>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'from_state))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'from_state))
  (cl:let* ((signed (cl:slot-value msg 'action)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'to_state))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'to_state))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'reward))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'terminal) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RLEnvSeedExperience>) istream)
  "Deserializes a message object of type '<RLEnvSeedExperience>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'from_state) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'from_state)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'action) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'to_state) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'to_state)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RLEnvSeedExperience>)))
  "Returns string type for a message object of type '<RLEnvSeedExperience>"
  "rl_msgs/RLEnvSeedExperience")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RLEnvSeedExperience)))
  "Returns string type for a message object of type 'RLEnvSeedExperience"
  "rl_msgs/RLEnvSeedExperience")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RLEnvSeedExperience>)))
  "Returns md5sum for a message object of type '<RLEnvSeedExperience>"
  "e195f7b7c1a41138d96a4af2de05b1b1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RLEnvSeedExperience)))
  "Returns md5sum for a message object of type 'RLEnvSeedExperience"
  "e195f7b7c1a41138d96a4af2de05b1b1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RLEnvSeedExperience>)))
  "Returns full string definition for message of type '<RLEnvSeedExperience>"
  (cl:format cl:nil "# Message that contains a seed experience to initialize the model~%float32[] from_state~%int32     action~%float32[] to_state~%float32   reward~%bool      terminal~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RLEnvSeedExperience)))
  "Returns full string definition for message of type 'RLEnvSeedExperience"
  (cl:format cl:nil "# Message that contains a seed experience to initialize the model~%float32[] from_state~%int32     action~%float32[] to_state~%float32   reward~%bool      terminal~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RLEnvSeedExperience>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'from_state) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'to_state) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RLEnvSeedExperience>))
  "Converts a ROS message object to a list"
  (cl:list 'RLEnvSeedExperience
    (cl:cons ':from_state (from_state msg))
    (cl:cons ':action (action msg))
    (cl:cons ':to_state (to_state msg))
    (cl:cons ':reward (reward msg))
    (cl:cons ':terminal (terminal msg))
))
