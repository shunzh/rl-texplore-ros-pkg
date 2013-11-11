; Auto-generated. Do not edit!


(cl:in-package rl_msgs-msg)


;//! \htmlinclude RLEnvDescription.msg.html

(cl:defclass <RLEnvDescription> (roslisp-msg-protocol:ros-message)
  ((num_actions
    :reader num_actions
    :initarg :num_actions
    :type cl:float
    :initform 0.0)
   (num_states
    :reader num_states
    :initarg :num_states
    :type cl:float
    :initform 0.0)
   (min_state_range
    :reader min_state_range
    :initarg :min_state_range
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (max_state_range
    :reader max_state_range
    :initarg :max_state_range
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (max_reward
    :reader max_reward
    :initarg :max_reward
    :type cl:float
    :initform 0.0)
   (reward_range
    :reader reward_range
    :initarg :reward_range
    :type cl:float
    :initform 0.0)
   (stochastic
    :reader stochastic
    :initarg :stochastic
    :type cl:boolean
    :initform cl:nil)
   (episodic
    :reader episodic
    :initarg :episodic
    :type cl:boolean
    :initform cl:nil)
   (title
    :reader title
    :initarg :title
    :type cl:string
    :initform ""))
)

(cl:defclass RLEnvDescription (<RLEnvDescription>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RLEnvDescription>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RLEnvDescription)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rl_msgs-msg:<RLEnvDescription> is deprecated: use rl_msgs-msg:RLEnvDescription instead.")))

(cl:ensure-generic-function 'num_actions-val :lambda-list '(m))
(cl:defmethod num_actions-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:num_actions-val is deprecated.  Use rl_msgs-msg:num_actions instead.")
  (num_actions m))

(cl:ensure-generic-function 'num_states-val :lambda-list '(m))
(cl:defmethod num_states-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:num_states-val is deprecated.  Use rl_msgs-msg:num_states instead.")
  (num_states m))

(cl:ensure-generic-function 'min_state_range-val :lambda-list '(m))
(cl:defmethod min_state_range-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:min_state_range-val is deprecated.  Use rl_msgs-msg:min_state_range instead.")
  (min_state_range m))

(cl:ensure-generic-function 'max_state_range-val :lambda-list '(m))
(cl:defmethod max_state_range-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:max_state_range-val is deprecated.  Use rl_msgs-msg:max_state_range instead.")
  (max_state_range m))

(cl:ensure-generic-function 'max_reward-val :lambda-list '(m))
(cl:defmethod max_reward-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:max_reward-val is deprecated.  Use rl_msgs-msg:max_reward instead.")
  (max_reward m))

(cl:ensure-generic-function 'reward_range-val :lambda-list '(m))
(cl:defmethod reward_range-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:reward_range-val is deprecated.  Use rl_msgs-msg:reward_range instead.")
  (reward_range m))

(cl:ensure-generic-function 'stochastic-val :lambda-list '(m))
(cl:defmethod stochastic-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:stochastic-val is deprecated.  Use rl_msgs-msg:stochastic instead.")
  (stochastic m))

(cl:ensure-generic-function 'episodic-val :lambda-list '(m))
(cl:defmethod episodic-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:episodic-val is deprecated.  Use rl_msgs-msg:episodic instead.")
  (episodic m))

(cl:ensure-generic-function 'title-val :lambda-list '(m))
(cl:defmethod title-val ((m <RLEnvDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:title-val is deprecated.  Use rl_msgs-msg:title instead.")
  (title m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RLEnvDescription>) ostream)
  "Serializes a message object of type '<RLEnvDescription>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'num_actions))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'num_states))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'min_state_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'min_state_range))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'max_state_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'max_state_range))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'max_reward))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'reward_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'stochastic) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'episodic) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'title))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'title))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RLEnvDescription>) istream)
  "Deserializes a message object of type '<RLEnvDescription>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'num_actions) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'num_states) (roslisp-utils:decode-single-float-bits bits)))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'min_state_range) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'min_state_range)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'max_state_range) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'max_state_range)))
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
    (cl:setf (cl:slot-value msg 'max_reward) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'reward_range) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'stochastic) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'episodic) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'title) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'title) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RLEnvDescription>)))
  "Returns string type for a message object of type '<RLEnvDescription>"
  "rl_msgs/RLEnvDescription")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RLEnvDescription)))
  "Returns string type for a message object of type 'RLEnvDescription"
  "rl_msgs/RLEnvDescription")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RLEnvDescription>)))
  "Returns md5sum for a message object of type '<RLEnvDescription>"
  "41ee0d621b8031a958ff6d1f587a3860")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RLEnvDescription)))
  "Returns md5sum for a message object of type 'RLEnvDescription"
  "41ee0d621b8031a958ff6d1f587a3860")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RLEnvDescription>)))
  "Returns full string definition for message of type '<RLEnvDescription>"
  (cl:format cl:nil "# Message that contains details about an RL enviroment/task~%float32 num_actions~%float32 num_states~%~%#Optional information to describe the range of a continous state~%#Some RL algorithms may need this to discretize the state space~%float32[] min_state_range~%float32[] max_state_range~%~%#Info needed for r-max some other methods~%float32 max_reward~%float32 reward_range~%~%bool stochastic~%bool episodic~%string title~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RLEnvDescription)))
  "Returns full string definition for message of type 'RLEnvDescription"
  (cl:format cl:nil "# Message that contains details about an RL enviroment/task~%float32 num_actions~%float32 num_states~%~%#Optional information to describe the range of a continous state~%#Some RL algorithms may need this to discretize the state space~%float32[] min_state_range~%float32[] max_state_range~%~%#Info needed for r-max some other methods~%float32 max_reward~%float32 reward_range~%~%bool stochastic~%bool episodic~%string title~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RLEnvDescription>))
  (cl:+ 0
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'min_state_range) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'max_state_range) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     4
     1
     1
     4 (cl:length (cl:slot-value msg 'title))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RLEnvDescription>))
  "Converts a ROS message object to a list"
  (cl:list 'RLEnvDescription
    (cl:cons ':num_actions (num_actions msg))
    (cl:cons ':num_states (num_states msg))
    (cl:cons ':min_state_range (min_state_range msg))
    (cl:cons ':max_state_range (max_state_range msg))
    (cl:cons ':max_reward (max_reward msg))
    (cl:cons ':reward_range (reward_range msg))
    (cl:cons ':stochastic (stochastic msg))
    (cl:cons ':episodic (episodic msg))
    (cl:cons ':title (title msg))
))
